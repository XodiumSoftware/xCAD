mod app;
mod auth;
mod db;
mod server;

use app::App;
use db::Database;
use rusqlite::Result;
use server::Server;

#[actix_web::main]
async fn main() -> Result<()> {
    let db = Database::new("xcad/data/xcad.db", "TEST_TABLE")?;
    let bind_address = "127.0.0.1:8080";
    Server::new(db, bind_address)
        .run()
        .await
        .map_err(|e| rusqlite::Error::ToSqlConversionFailure(Box::new(e)))?;
    if let Err(e) = eframe::run_native(
        "xCAD Frontend",
        eframe::NativeOptions::default(),
        Box::new(|_cc| Ok(Box::new(App::default()) as Box<dyn eframe::App>)),
    ) {
        eprintln!("Error running eframe: {}", e);
    }
    Ok(())
}
