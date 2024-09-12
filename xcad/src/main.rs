#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

const TITLE: &str = "xCAD Editor";

fn main() -> eframe::Result {
    env_logger::init();
    eframe::run_native(
        TITLE,
        eframe::NativeOptions::default(),
        Box::new(|_cc| {
            Ok::<Box<dyn eframe::App>, Box<dyn std::error::Error + Send + Sync>>(Box::new(
                xcad::App {},
            ))
        }),
    )
}
