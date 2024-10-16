use crate::bim::BIMObject;
use sqlx::sqlite::SqlitePoolOptions;
use sqlx::{Pool, Result, Sqlite};
use tokio::sync::OnceCell;

#[derive(Clone)]
pub struct DBManager {
    pool: Pool<Sqlite>,
    table_initialized: OnceCell<()>,
}

impl DBManager {
    pub async fn new(db_url: &'static str) -> Result<Self, Box<dyn std::error::Error>> {
        Ok(Self {
            pool: SqlitePoolOptions::new()
                .max_connections(5)
                .connect(db_url)
                .await?,
            table_initialized: OnceCell::new(),
        })
    }

    async fn ensure_table(&self) -> Result<()> {
        self.table_initialized
            .get_or_init(|| async {
                sqlx::query!(
                    "CREATE TABLE IF NOT EXISTS bim_objects (
                        id TEXT PRIMARY KEY,
                        name TEXT NOT NULL,
                        desc TEXT
                    )"
                )
                .execute(&self.pool)
                .await
            })
            .await
            .clone()
    }

    pub async fn set_obj(&self, bim: &BIMObject) -> Result<u64> {
        self.ensure_table().await?;
        sqlx::query!(
            "INSERT INTO bim_objects (id, name, desc) VALUES ($1, $2, $3)
            ON CONFLICT (id) DO UPDATE SET name = EXCLUDED.name, desc = EXCLUDED.desc",
            bim.id,
            bim.name,
            bim.desc
        )
        .execute(&self.pool)
        .await
        .map(|result| result.rows_affected())
    }

    pub async fn get_obj(&self, id: &str) -> Result<BIMObject> {
        sqlx::query_as!(
            BIMObject,
            "SELECT id, name, desc FROM bim_objects WHERE id = $1",
            id
        )
        .fetch_one(&self.pool)
        .await
    }
}
