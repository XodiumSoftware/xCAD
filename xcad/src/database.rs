use rusqlite::{params, Connection, Result};

#[derive(Debug)]
struct User {
    id: i32,
    name: String,
    data: Option<Vec<u8>>,
}

pub struct Database {
    conn: Connection,
}

impl Database {
    pub fn new(db_path: &str) -> Result<Self> {
        let conn = Connection::open(db_path)?;
        Ok(Database { conn })
    }

    pub fn run() -> Result<()> {
        let conn = Connection::open("xcad.db")?;

        conn.execute(
            "CREATE TABLE IF NOT EXISTS user (
                id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                data BLOB
            )",
            [],
        )?;

        conn.execute(
            "INSERT INTO user (name, data) VALUES (?1, ?2)",
            params!["Alice", "Some data"],
        )?;

        let mut stmt = conn.prepare("SELECT id, name, data FROM user")?;
        let user_iter = stmt.query_map([], |row| {
            Ok(User {
                id: row.get(0)?,
                name: row.get(1)?,
                data: row.get(2)?,
            })
        })?;

        for user in user_iter {
            println!("Found user {:?}", user?);
        }

        Ok(())
    }
}
