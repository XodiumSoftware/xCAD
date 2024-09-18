#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod app;
pub use app::App;
mod database;
pub use database::Database;

const TITLE: &str = "xCAD Editor";
const DB_PATH: &str = "database/xcad.db";
const INIT_DB_ERROR: &str = "Failed to initialize database";
const CREATE_SCHEMA_ERROR: &str = "Failed to create schema";

fn main() -> eframe::Result {
    env_logger::init();
    let db = Database::new(DB_PATH).expect(INIT_DB_ERROR);
    db.create_schema().expect(CREATE_SCHEMA_ERROR);
    eframe::run_native(
        TITLE,
        eframe::NativeOptions::default(),
        Box::new(|cc| Ok(Box::new(App::new(cc)))),
    )
}
