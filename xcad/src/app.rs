#[derive(serde::Deserialize, serde::Serialize)]
#[serde(default)]
pub struct App {
    label: String,
    #[serde(skip)]
    value: f32,
}

impl Default for App {
    fn default() -> Self {
        Self {
            label: String::from("Hello World!"),
            value: 2.7,
        }
    }
}

impl App {
    pub fn new(cc: &eframe::CreationContext<'_>) -> Self {
        if let Some(storage) = cc.storage {
            return eframe::get_value(storage, eframe::APP_KEY).unwrap_or_default();
        }
        Default::default()
    }
}

impl eframe::App for App {
    fn save(&mut self, storage: &mut dyn eframe::Storage) {
        eframe::set_value(storage, eframe::APP_KEY, self);
    }

    fn update(&mut self, ctx: &eframe::egui::Context, _frame: &mut eframe::Frame) {
        eframe::egui::TopBottomPanel::top("top_panel").show(ctx, |ui: &mut eframe::egui::Ui| {
            eframe::egui::menu::bar(ui, |ui: &mut eframe::egui::Ui| {
                if !cfg!(target_arch = "wasm32") {
                    ui.menu_button("File", |ui: &mut eframe::egui::Ui| {
                        if ui.button("Quit").clicked() {
                            ctx.send_viewport_cmd(eframe::egui::ViewportCommand::Close);
                        }
                    });
                    ui.add_space(16.0);
                }
                eframe::egui::widgets::global_dark_light_mode_buttons(ui);
            });
        });

        eframe::egui::CentralPanel::default().show(ctx, |ui: &mut eframe::egui::Ui| {
            ui.heading("eframe template");

            ui.horizontal(|ui: &mut eframe::egui::Ui| {
                ui.label("Write something: ");
                ui.text_edit_singleline(&mut self.label);
            });

            ui.add(eframe::egui::Slider::new(&mut self.value, 0.0..=10.0).text("value"));
            if ui.button("Increment").clicked() {
                self.value += 1.0;
            }

            ui.separator();

            ui.add(eframe::egui::github_link_file!(
                "https://github.com/emilk/eframe_template/blob/main/",
                "Source code."
            ));

            ui.with_layout(
                eframe::egui::Layout::bottom_up(eframe::egui::Align::LEFT),
                |ui: &mut eframe::egui::Ui| {
                    powered_by_egui_and_eframe(ui);
                    eframe::egui::warn_if_debug_build(ui);
                },
            );
        });
    }
}

fn powered_by_egui_and_eframe(ui: &mut eframe::egui::Ui) {
    ui.horizontal(|ui: &mut eframe::egui::Ui| {
        ui.spacing_mut().item_spacing.x = 0.0;
        ui.label("Powered by ");
        ui.hyperlink_to("egui", "https://github.com/emilk/egui");
        ui.label(" and ");
        ui.hyperlink_to(
            "eframe",
            "https://github.com/emilk/egui/tree/master/crates/eframe",
        );
        ui.label(".");
    });
}
