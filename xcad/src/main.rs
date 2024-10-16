use db::DBManager;
mod bim;
mod db;
mod server;
use server::ServerManager;

const SERVER_ADDR: &str = "127.0.0.1:8080";
const ENDPOINT: &str = "/cloud";
const LOG_LEVEL: &str = "info";

const DB_URL: &'static str = "sqlite://xcad.db";
const CONN_ERR: &str = "Failed to connect to the database";

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    ServerManager::new(SERVER_ADDR, ENDPOINT, LOG_LEVEL)
        .run(DBManager::new(DB_URL).await.expect(CONN_ERR))
        .await
}
