use db::DBManager;
use server::ServerManager;
mod bim;
mod db;
mod server;

const SERVER_ADDR: &str = "127.0.0.1:8080";
const ENDPOINT: &str = "/cloud";
const DB_URL: &str = "xcad/src/xcad.db";
const CONN_ERR: &str = "Failed to connect to the database";

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    ServerManager::new(SERVER_ADDR, ENDPOINT)
        .run(DBManager::new(DB_URL).expect(CONN_ERR))
        .await
}
