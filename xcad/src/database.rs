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
