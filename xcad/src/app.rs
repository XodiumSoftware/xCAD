pub struct App {}
use eframe::egui;

// Header
const IS_TARGET_WASM32: bool = cfg!(target_arch = "wasm32");
const MENU_FILE_TITLE: &str = "File";
const MENU_QUIT_TITLE: &str = "🚪 Quit";

// Footer
const COPYRIGHT: &str = "©️ 2024 XODIUM SOFTWARE INC";
const EFRAME_URL: &str = "https://github.com/emilk/egui/tree/master/crates/eframe";
const EGUI_URL: &str = "https://github.com/emilk/egui";

impl eframe::App for App {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        self.header(ctx);
        self.footer(ctx);
        self.body(ctx);
    }
}

impl App {
    fn header(&mut self, ctx: &egui::Context) {
        egui::TopBottomPanel::top("top_panel").show(ctx, |ui| {
            egui::menu::bar(ui, |ui| {
                if !IS_TARGET_WASM32 {
                    ui.menu_button(MENU_FILE_TITLE, |ui| {
                        if ui.button(MENU_QUIT_TITLE).clicked() {
                            ctx.send_viewport_cmd(egui::ViewportCommand::Close);
                        }
                    });
                }
                ui.with_layout(egui::Layout::right_to_left(egui::Align::Min), |ui| {
                    egui::widgets::global_dark_light_mode_switch(ui);
                });
            });
        });
    }

    fn body(&mut self, ctx: &egui::Context) {
        let table_data = vec![
            (
                "General",
                vec![
                    ("Color", "Yellow"),
                    ("Layer", "AL32 ----_ BINNENKOZIJN"),
                    ("Linetype", "ByLayer"),
                    ("Linetype scale", "1"),
                    ("Lineweight", "ByLayer"),
                    ("Transparency", "ByLayer"),
                ],
            ),
            (
                "View",
                vec![
                    ("Elevation", "0 mm"),
                    ("Perspective", "Off"),
                    ("Lens length", "50.000 mm"),
                    ("Field of view", "38.58"),
                    ("Height", "43955.762 mm"),
                    ("Width", "64214.102 mm"),
                ],
            ),
            (
                "Misc",
                vec![("Annotation scale", "1:1"), ("Default lighting", "On")],
            ),
        ];
        let available_rect = ctx.available_rect();
        egui::CentralPanel::default().show(ctx, |ui| {
            let text_height = egui::TextStyle::Body
                .resolve(ui.style())
                .size
                .max(ui.spacing().interact_size.y);
            for (category, properties) in &table_data {
                egui::CollapsingHeader::new(egui::RichText::new(*category).strong())
                    .default_open(true)
                    .show(ui, |ui| {
                        egui_extras::TableBuilder::new(ui)
                            .striped(true)
                            .resizable(true)
                            .cell_layout(egui::Layout::left_to_right(egui::Align::Center))
                            .column(egui_extras::Column::auto())
                            .column(
                                egui_extras::Column::remainder()
                                    .at_least(40.0)
                                    .clip(true)
                                    .resizable(true),
                            )
                            .min_scrolled_height(0.0)
                            .max_scroll_height(available_rect.height())
                            .body(|mut body| {
                                for (property, value) in properties {
                                    body.row(text_height, |mut row| {
                                        row.col(|ui| {
                                            ui.label(*property);
                                        });
                                        row.col(|ui| {
                                            ui.label(*value);
                                        });
                                    });
                                }
                            });
                    });
            }
        });
    }

    fn footer(&mut self, ctx: &egui::Context) {
        egui::TopBottomPanel::bottom("bottom_panel").show(ctx, |ui| {
            ui.horizontal(|ui| {
                ui.label(COPYRIGHT);
                ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                    ui.spacing_mut().item_spacing.x = 4.0;
                    ui.hyperlink_to("eframe", EFRAME_URL);
                    ui.label(" and ");
                    ui.hyperlink_to("egui", EGUI_URL);
                    ui.label("Powered by ");
                });
            });
        });
    }
}
