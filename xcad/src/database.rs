use rusqlite::{params, Connection, Result};

#[derive(Debug)]
pub struct User {
    pub id: i32,
    pub name: String,
    pub data: Option<Vec<u8>>,
}

pub struct Database {
    conn: Connection,
}

impl Database {
    pub fn new(db_path: &str) -> Result<Self> {
        let conn = Connection::open(db_path)?;
        Ok(Database { conn })
    }

    pub fn create_schema(&self) -> Result<()> {
        self.conn.execute(
            "CREATE TABLE IF NOT EXISTS user (
                id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                data BLOB
            )",
            [],
        )?;
        Ok(())
    }

    pub fn insert_user(&self, name: &str, data: Option<&[u8]>) -> Result<()> {
        self.conn.execute(
            "INSERT INTO user (name, data) VALUES (?1, ?2)",
            params![name, data],
        )?;
        Ok(())
    }

    pub fn fetch_users(&self) -> Result<Vec<User>> {
        let mut stmt = self.conn.prepare("SELECT id, name, data FROM user")?;
        let user_iter = stmt.query_map([], |row| {
            Ok(User {
                id: row.get(0)?,
                name: row.get(1)?,
                data: row.get(2)?,
            })
        })?;

        let mut users = Vec::new();
        for user in user_iter {
            users.push(user?);
        }
        Ok(users)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rusqlite::Result;
    use std::fs;

    fn setup_test_db() -> Result<Database> {
        let db_path = "test.sqlite";
        if fs::remove_file(db_path).is_err() {}
        let db = Database::new(db_path)?;
        db.create_schema()?;
        Ok(db)
    }

    #[test]
    fn test_create_schema() {
        setup_test_db().expect("Failed to set up test database");
    }

    #[test]
    fn test_insert_user() {
        let db = setup_test_db().expect("Failed to set up test database");
        db.insert_user("Alice", Some(b"data"))
            .expect("Failed to insert user");
        let users = db.fetch_users().expect("Failed to fetch users");
        assert_eq!(users.len(), 1);
        assert_eq!(users[0].name, "Alice");
        assert_eq!(users[0].data, Some(b"data".to_vec()));
    }

    #[test]
    fn test_fetch_users() {
        let db = setup_test_db().expect("Failed to set up test database");
        db.insert_user("Alice", Some(b"data"))
            .expect("Failed to insert user");
        db.insert_user("Bob", None).expect("Failed to insert user");

        let users = db.fetch_users().expect("Failed to fetch users");
        assert_eq!(users.len(), 2);
        assert_eq!(users[0].name, "Alice");
        assert_eq!(users[0].data, Some(b"data".to_vec()));
        assert_eq!(users[1].name, "Bob");
        assert_eq!(users[1].data, None);
    }
}
