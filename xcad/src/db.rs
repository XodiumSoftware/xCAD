use rusqlite::{params, Connection, OptionalExtension, Result};
use std::{fs, path::Path};

pub struct DBManager {
    conn: Connection,
    table_name: String,
}

#[allow(dead_code)]
impl DBManager {
    pub fn new(db_path: &str, table_name: &str) -> Result<Self> {
        Self::ensure_db_path_exists(db_path)?;
        let conn = Connection::open(db_path)?;
        Ok(DBManager {
            conn,
            table_name: table_name.to_string(),
        })
    }

    fn ensure_db_path_exists(db_path: &str) -> Result<()> {
        let path = Path::new(db_path);

        if let Some(parent) = path.parent() {
            if !parent.exists() {
                fs::create_dir_all(parent).map_err(|e| {
                    rusqlite::Error::FromSqlConversionFailure(
                        0,
                        rusqlite::types::Type::Text,
                        Box::new(e),
                    )
                })?;
            }
        }

        if !path.exists() {
            fs::File::create(path).map_err(|e| {
                rusqlite::Error::FromSqlConversionFailure(
                    0,
                    rusqlite::types::Type::Text,
                    Box::new(e),
                )
            })?;
        }
        Ok(())
    }

    pub fn init(&self) -> Result<()> {
        self.conn.execute(
            &format!(
                "CREATE TABLE IF NOT EXISTS {} (
              key TEXT PRIMARY KEY,
              value TEXT
              )",
                self.table_name
            ),
            [],
        )?;
        Ok(())
    }

    pub fn set_data(&self, key: &str, value: &str) -> Result<()> {
        self.conn.execute(
            &format!(
                "INSERT OR REPLACE INTO {} (key, value) VALUES (?1, ?2)",
                self.table_name
            ),
            params![key, value],
        )?;
        Ok(())
    }

    pub fn get_data(&self, key: &str) -> Result<Option<String>> {
        Ok(self
            .conn
            .prepare(&format!(
                "SELECT value FROM {} WHERE key = ?1",
                self.table_name
            ))?
            .query_row(params![key], |row| row.get(0))
            .optional()?)
    }

    pub fn update_data(&self, key: &str, value: &str) -> Result<()> {
        self.conn.execute(
            &format!("UPDATE {} SET value = ?1 WHERE key = ?2", self.table_name),
            params![value, key],
        )?;
        Ok(())
    }

    pub fn delete_data(&self, key: &str) -> Result<()> {
        self.conn.execute(
            &format!("DELETE FROM {} WHERE key = ?1", self.table_name),
            params![key],
        )?;
        Ok(())
    }

    pub fn delete_table(&self) -> Result<()> {
        self.conn
            .execute(&format!("DROP TABLE IF EXISTS {}", self.table_name), [])?;
        Ok(())
    }
}
