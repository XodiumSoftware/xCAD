use eframe::egui;

// Header
const IS_TARGET_WASM32: bool = cfg!(target_arch = "wasm32");
const MENU_FILE_TITLE: &str = "File";
const MENU_QUIT_TITLE: &str = "🚪 Quit";

// Body
const TABLE_DATA: &[(&str, &[(&str, &str)])] = &[
    (
        "General",
        &[
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
        &[
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
        &[("Annotation scale", "1:1"), ("Default lighting", "On")],
    ),
];

// Footer
const COPYRIGHT: &str = "© 2024 XODIUM SOFTWARE INC";
const EFRAME_URL: &str = "https://github.com/emilk/egui/tree/master/crates/eframe";
const EGUI_URL: &str = "https://github.com/emilk/egui";

#[derive(serde::Deserialize, serde::Serialize)]
#[serde(default)]
pub struct App {
    init_col_x: f32,
    min_col_x: f32,
}

impl Default for App {
    fn default() -> Self {
        Self {
            init_col_x: 120.0,
            min_col_x: 40.0,
        }
    }
}

impl eframe::App for App {
    fn save(&mut self, storage: &mut dyn eframe::Storage) {
        eframe::set_value(storage, eframe::APP_KEY, self);
    }

    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        self.header(ctx);
        self.footer(ctx);
        self.body(ctx);
    }
}

impl App {
    pub fn new(cc: &eframe::CreationContext<'_>) -> Self {
        if let Some(storage) = cc.storage {
            return eframe::get_value(storage, eframe::APP_KEY).unwrap_or_default();
        }
        Default::default()
    }

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

        let text_height = egui::TextStyle::Body
            .resolve(&ctx.style())
            .size
            .max(ctx.style().spacing.interact_size.y);


        egui::CentralPanel::default().show(ctx, |ui| {
            egui::ScrollArea::vertical().show(ui, |ui| {
                for (category, properties) in TABLE_DATA.iter() {
                    egui::CollapsingHeader::new(egui::RichText::new(*category).strong())
                        .default_open(true)
                        .show(ui, |ui| {
                            egui_extras::TableBuilder::new(ui)
                                .striped(true)
                                .resizable(true)
                                .column(
                                    egui_extras::Column::initial(self.init_col_x)
                                        .at_least(self.min_col_x),
                                )
                                .column(egui_extras::Column::remainder().at_least(self.min_col_x))
                                .body(|mut body| {
                                    for (property, value) in properties.iter() {
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
