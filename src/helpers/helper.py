import random
import string
from typing import Optional

from ezdxf import filemanagement as fm
from ezdxf.lldxf import const
from PySide6.QtCore import QPoint
from PySide6.QtWidgets import QApplication, QGraphicsView, QWidget

from configs.q_configs import AspectRatioModeTypes, ModuleType


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def complex_id_generator(char_len: int = 6) -> str:
        """Generate a complex ID."""
        chars = string.ascii_letters + string.digits
        return "".join(random.choice(chars) for _ in range(char_len))

    @staticmethod
    def center_ui_on_screen(ui: QWidget) -> None:
        """Centers the window on the primary screen."""
        screen_center = QApplication.primaryScreen().geometry().center()
        ui_size = ui.size()
        ui.move(screen_center - QPoint(ui_size.width() // 2, ui_size.height() // 2))

    @staticmethod
    def set_ui_size(ui: QWidget, size: Optional[tuple[int, int]] = None) -> None:
        """Sets the size of the UI."""
        if size is None:
            ui.resize(ui.sizeHint())
        else:
            width, height = size
            ui.resize(width, height)

    @staticmethod
    def toggle_ui_visibility(uis: list[QWidget]) -> None:
        """Toggles the visibility of UI(s)."""
        for ui in uis:
            ui.setVisible(not ui.isVisible())
            if ui.isVisible():
                Helper.center_ui_on_screen(ui)

    @staticmethod
    def switch_modules(module: ModuleType.StackedWidget.value) -> None:
        """Switches the modules."""
        current_index = module.currentIndex()
        new_index = (current_index + 1) % module.count()
        module.setCurrentIndex(new_index)

    @staticmethod
    def fit_scene_in_view(instance: QGraphicsView) -> None:
        """Fits the scene in the view."""
        instance.fitInView(
            instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
        )

    @staticmethod
    def read_dwg_file(file_path: str) -> list[dict]:
        """Reads a DWG file and returns the entity information."""
        entity_info = []
        try:
            doc = fm.readfile(file_path)
            msp = doc.modelspace()

            for entity in msp.query("*"):
                entity_type = entity.dxftype()
                layer_name = entity.dxf.layer

                properties = []

                if entity_type == "LINE":
                    properties = {
                        "Entity Type": entity_type,
                        "Layer": layer_name,
                        "Start Point": entity.dxf.start,
                        "End Point": entity.dxf.end,
                        "Color": entity.dxf.color,
                        "Line Type": entity.dxf.linetype,
                        "Line Weight": entity.dxf.lineweight,
                    }
                elif entity_type in ("TEXT", "MTEXT"):
                    properties = {
                        "Entity Type": entity_type,
                        "Layer": layer_name,
                        "Text Content": entity.dxf.text,
                        "Color": entity.dxf.color,
                        "Line Type": entity.dxf.linetype,
                        "Line Weight": entity.dxf.lineweight,
                    }
                elif entity_type == "CIRCLE":
                    properties = {
                        "Entity Type": entity_type,
                        "Layer": layer_name,
                        "Center": entity.dxf.center,
                        "Radius": entity.dxf.radius,
                        "Color": entity.dxf.color,
                        "Line Type": entity.dxf.linetype,
                        "Line Weight": entity.dxf.lineweight,
                    }

                entity_info.append(properties)

        except const.DXFError as e:
            print(f"Error reading DWG file: {e}")

        return entity_info

    # TODO: add method that sends back the properties after editing.
