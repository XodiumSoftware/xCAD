pub struct App {}

impl eframe::App for App {
    fn update(&mut self, ctx: &eframe::egui::Context, _frame: &mut eframe::Frame) {
        self.header(ctx);
        self.body(ctx);
        self.footer(ctx);
    }
}

impl App {
    fn header(&mut self, ctx: &eframe::egui::Context) {
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
    }

    fn body(&mut self, ctx: &eframe::egui::Context) {
        eframe::egui::CentralPanel::default().show(ctx, |ui: &mut eframe::egui::Ui| {
            ui.vertical_centered(|ui| {
                ui.heading(eframe::egui::RichText::new("xCAD ObjectX").strong());
            });

            ui.horizontal(|ui: &mut eframe::egui::Ui| {
                ui.label("Write something: ");
                ui.text_edit_singleline(&mut "Hello World!");
            });

            ui.separator();

            ui.add(eframe::egui::github_link_file!(
                "https://github.com/XodiumSoftware/xCAD/blob/main/",
                "Source code."
            ));
        });
    }

    fn footer(&mut self, ctx: &eframe::egui::Context) {
        eframe::egui::TopBottomPanel::bottom("bottom_panel").show(
            ctx,
            |ui: &mut eframe::egui::Ui| {
                ui.horizontal(|ui: &mut eframe::egui::Ui| {
                    ui.spacing_mut().item_spacing.x = 0.0;
                    ui.label("© 2024 XODIUM SOFTWARE INC");
                    ui.with_layout(
                        eframe::egui::Layout::right_to_left(eframe::egui::Align::Center),
                        |ui| {
                            ui.spacing_mut().item_spacing.x = 4.0;
                            ui.label(".");
                            ui.hyperlink_to(
                                "eframe",
                                "https://github.com/emilk/egui/tree/master/crates/eframe",
                            );
                            ui.label(" and ");
                            ui.hyperlink_to("egui", "https://github.com/emilk/egui");
                            ui.label("Powered by ");
                        },
                    );
                });
            },
        );
    }
}
