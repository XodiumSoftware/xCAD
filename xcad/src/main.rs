mod db;
mod server;

use db::DBManager;
use rusqlite::Result;
use server::Server;

#[actix_web::main]
async fn main() -> Result<()> {
    let db = DBManager::new("xcad/data/xcad.db", "DEBUG")?;
    Server::new(db)
        .run()
        .await
        .map_err(|e| rusqlite::Error::ToSqlConversionFailure(Box::new(e)))
}
