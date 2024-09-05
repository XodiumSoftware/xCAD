use egui::Vec2b;

fn main() {
    let mut window_options: WindowOptions = WindowOptions::default();
    let mut open: bool = true;
    let ctx: &_ = &egui::Context::new();
    window_options.show(ctx, &mut open);
}

#[derive(Clone, PartialEq)]
#[cfg_attr(feature = "serde", derive(serde::Deserialize, serde::Serialize))]
pub struct WindowOptions {
    title: String,
    title_bar: bool,
    closable: bool,
    collapsible: bool,
    resizable: bool,
    constrain: bool,
    scroll2: Vec2b,
    disabled_time: f64,

    anchored: bool,
    anchor: egui::Align2,
    anchor_offset: egui::Vec2,
}

impl Default for WindowOptions {
    fn default() -> Self {
        Self {
            title: "🗖 Window Options".to_owned(),
            title_bar: true,
            closable: true,
            collapsible: true,
            resizable: true,
            constrain: true,
            scroll2: Vec2b::TRUE,
            disabled_time: f64::NEG_INFINITY,
            anchored: false,
            anchor: egui::Align2::RIGHT_TOP,
            anchor_offset: egui::Vec2::ZERO,
        }
    }
}

impl crate::Demo for WindowOptions {
    fn name(&self) -> &'static str {
        "🗖 Window Options"
    }

    fn show(&mut self, ctx: &egui::Context, open: &mut bool) {
        let Self {
            title,
            title_bar,
            closable,
            collapsible,
            resizable,
            constrain,
            scroll2,
            disabled_time,
            anchored,
            anchor,
            anchor_offset,
        } = self.clone();

        let enabled = ctx.input(|i: &egui::InputState| i.time) - disabled_time > 2.0;
        if !enabled {
            ctx.request_repaint();
        }

        use crate::View as _;
        let mut window: egui::Window<'_> = egui::Window::new(title)
            .id(egui::Id::new("demo_window_options")) // required since we change the title
            .resizable(resizable)
            .constrain(constrain)
            .collapsible(collapsible)
            .title_bar(title_bar)
            .scroll(scroll2)
            .enabled(enabled);
        if closable {
            window = window.open(open);
        }
        if anchored {
            window = window.anchor(anchor, anchor_offset);
        }
        window.show(ctx, |ui: &mut egui::Ui| self.ui(ui));
    }
}

impl crate::View for WindowOptions {
    fn ui(&mut self, ui: &mut egui::Ui) {
        let Self {
            title,
            title_bar,
            closable,
            collapsible,
            resizable,
            constrain,
            scroll2,
            disabled_time: _,
            anchored,
            anchor,
            anchor_offset,
        } = self;
        ui.horizontal(|ui: &mut egui::Ui| {
            ui.label("title:");
            ui.text_edit_singleline(title);
        });

        ui.horizontal(|ui: &mut egui::Ui| {
            ui.group(|ui: &mut egui::Ui| {
                ui.vertical(|ui: &mut egui::Ui| {
                    ui.checkbox(title_bar, "title_bar");
                    ui.checkbox(closable, "closable");
                    ui.checkbox(collapsible, "collapsible");
                    ui.checkbox(resizable, "resizable");
                    ui.checkbox(constrain, "constrain")
                        .on_hover_text("Constrain window to the screen");
                    ui.checkbox(&mut scroll2[0], "hscroll");
                    ui.checkbox(&mut scroll2[1], "vscroll");
                });
            });
            ui.group(|ui: &mut egui::Ui| {
                ui.vertical(|ui: &mut egui::Ui| {
                    ui.checkbox(anchored, "anchored");
                    if !*anchored {
                        ui.disable();
                    }
                    ui.horizontal(|ui: &mut egui::Ui| {
                        ui.label("x:");
                        ui.selectable_value(&mut anchor[0], egui::Align::LEFT, "Left");
                        ui.selectable_value(&mut anchor[0], egui::Align::Center, "Center");
                        ui.selectable_value(&mut anchor[0], egui::Align::RIGHT, "Right");
                    });
                    ui.horizontal(|ui: &mut egui::Ui| {
                        ui.label("y:");
                        ui.selectable_value(&mut anchor[1], egui::Align::TOP, "Top");
                        ui.selectable_value(&mut anchor[1], egui::Align::Center, "Center");
                        ui.selectable_value(&mut anchor[1], egui::Align::BOTTOM, "Bottom");
                    });
                    ui.horizontal(|ui: &mut egui::Ui| {
                        ui.label("Offset:");
                        ui.add(egui::DragValue::new(&mut anchor_offset.x));
                        ui.add(egui::DragValue::new(&mut anchor_offset.y));
                    });
                });
            });
        });

        ui.separator();
        let on_top = Some(ui.layer_id()) == ui.ctx().top_layer_id();
        ui.label(format!("This window is on top: {on_top}."));

        ui.separator();
        ui.horizontal(|ui: &mut egui::Ui| {
            if ui.button("Disable for 2 seconds").clicked() {
                self.disabled_time = ui.input(|i: &egui::InputState| i.time);
            }
            egui::reset_button(ui, self, "Reset");
            ui.add(crate::egui_github_link_file!());
        });
    }
}
