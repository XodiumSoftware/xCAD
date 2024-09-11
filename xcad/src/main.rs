#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

fn main() -> eframe::Result {
    env_logger::init();

    eframe::run_native(
        "xCAD",
        eframe::NativeOptions::default(),
        Box::new(|cc| Ok(Box::new(xcad::App::new(cc)))),
    )
}
