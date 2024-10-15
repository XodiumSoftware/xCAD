use crate::bim::BIMObject;
use sqlx::postgres::PgPoolOptions;
use sqlx::{Pool, Postgres, Result};

#[derive(Clone)]
pub struct DBManager {
    pool: Pool<Postgres>,
}

impl DBManager {
    pub async fn new(db_url: &'static str) -> Result<Self, Box<dyn std::error::Error>> {
        Ok(Self {
            pool: PgPoolOptions::new()
                .max_connections(5)
                .connect(db_url)
                .await?,
        })
    }

    pub async fn set_obj(&self, bim: &BIMObject) -> Result<u64> {
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
