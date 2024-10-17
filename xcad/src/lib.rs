use eframe::egui::Ui;
use wasm_bindgen::prelude::*;

fn update(ui: &mut Ui) {
    ui.label("Hello, world!");
}

#[wasm_bindgen(start)]
pub fn start() -> Result<(), JsValue> {
    let canvas_id = "the_canvas_id";
    let painter_id = "the_painter_id";
    let mut app = eframe::WebApp::new(canvas_id, painter_id);
    app.run(update);
    Ok(())
}
