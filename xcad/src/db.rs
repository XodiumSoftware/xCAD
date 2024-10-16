use crate::bim::BIMObject;
use rusqlite::{params, Connection, Result};
use std::sync::{Arc, Mutex};

#[derive(Clone)]
pub struct DBManager {
    conn: Arc<Mutex<Connection>>,
}

impl DBManager {
    pub fn new(db_url: &str) -> Result<Self> {
        Ok(Self {
            conn: Arc::new(Mutex::new(Connection::open(db_url)?)),
        })
    }

    pub fn set_obj(&self, bim: &BIMObject) -> Result<usize> {
        let conn = self.conn.lock().unwrap();
        conn.execute(
            "INSERT INTO bim_objects (id, name, desc) VALUES (?1, ?2, ?3)
            ON CONFLICT(id) DO UPDATE SET name = excluded.name, desc = excluded.desc",
            params![bim.id, bim.name, bim.desc],
        )
    }

    pub fn get_obj(&self, id: u32) -> Result<BIMObject> {
        let conn = self.conn.lock().unwrap();
        conn.query_row(
            "SELECT id, name, desc FROM bim_objects WHERE id = ?1",
            params![id],
            |row| {
                // Using `get` with tuple destructuring for cleaner code
                let (id, name, desc): (u32, String, String) = row.get(0)?;
                Ok(BIMObject { id, name, desc })
            },
        )
    }
}
