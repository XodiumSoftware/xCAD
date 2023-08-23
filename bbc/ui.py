from functools import partial

from delegates.graphics_view_delegate import GraphicsViewDelegate
from enums.matrix_enums import Matrices
from enums.module_enums import Buttons
from enums.q_enums import ModuleType
from enums.ui_enums import UIs
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget


class UI(QMainWindow):
    """A class to handle the UI."""

    def __init__(self) -> None:
        """Initialize the MainUI."""
        super().__init__()

        self._main_module_0 = ModuleHandler(Matrices.Matrix0)
        self._main_module_1 = ModuleHandler(Matrices.Matrix2)
        self._configurator_module_0 = ModuleHandler(Matrices.Matrix1)
        self._frame_view_2d_view = GraphicsViewDelegate()
        self._signal_handler = SignalHandler()
        self._ui_handler = UIHandler()

        self._main_ui = QWidget()
        self._configurator_ui = QWidget()
        self._frame_view_ui = QWidget()

        self._events_handler = EventsHandler()

        self.setup_ui()

    def setup_ui(self) -> None:
        """Setup the UIs."""
        main_ui_info = UIs.MainUI.value
        configurator_ui_info = UIs.ConfiguratorUI.value
        frame_2d_view_ui_info = UIs.Frame2DView.value

        self._main_ui.setWindowTitle(main_ui_info["title"])
        self._configurator_ui.setWindowTitle(configurator_ui_info["title"])
        self._frame_view_ui.setWindowTitle(frame_2d_view_ui_info["title"])

        self._main_ui.setWindowIcon(QIcon(main_ui_info["icon"]))
        self._configurator_ui.setWindowIcon(QIcon(configurator_ui_info["icon"]))
        self._frame_view_ui.setWindowIcon(QIcon(frame_2d_view_ui_info["icon"]))

        self._ui_handler.center_ui_on_screen_handler(self)

        self._ui_handler.set_ui_size(self._main_ui, main_ui_info["initial_size"])
        self._ui_handler.set_ui_size(
            self._configurator_ui, configurator_ui_info["initial_size"]
        )
        self._ui_handler.set_ui_size(
            self._frame_view_ui, frame_2d_view_ui_info["initial_size"]
        )

        self._events_handler.quit_on_key_press_event(self._main_ui)
        self._events_handler.quit_on_key_press_event(self._configurator_ui)
        self._events_handler.quit_on_key_press_event(self._frame_view_ui)

        self._main_modules_stack = ModuleType.StackedWidget.value(self._main_ui)
        self._main_modules_stack.addWidget(self._main_module_0)
        self._main_modules_stack.addWidget(self._main_module_1)

        self._main_ui_layout = QGridLayout(self._main_ui)
        self._main_ui_layout.addWidget(self._main_modules_stack)

        self._configurator_modules_stack = ModuleType.StackedWidget.value(self._main_ui)
        self._configurator_modules_stack.addWidget(self._configurator_module_0)

        self._configurator_ui_layout = QGridLayout(self._configurator_ui)
        self._configurator_ui_layout.addWidget(self._configurator_modules_stack)

        self._frame_view_ui_layout = QGridLayout(self._frame_view_ui)
        self._frame_view_ui_layout.addWidget(self._frame_view_2d_view)

        if main_ui_info["initial_visibility"]:
            self._main_ui.show()
        else:
            self._main_ui.hide()

        if configurator_ui_info["initial_visibility"]:
            self._configurator_ui.show()
        else:
            self._configurator_ui.hide()

        if frame_2d_view_ui_info["initial_visibility"]:
            self._frame_view_ui.show()
        else:
            self._frame_view_ui.hide()

        self.setup_connections()

    def setup_connections(self) -> None:
        """Setup the connections."""
        self._main_module_0.module_connection(
            Buttons.AutoFrameCAD,
            partial(
                self._ui_handler.switch_modules,
                module=self._main_modules_stack,
            ),
        )
        self._main_module_1.module_connection(
            Buttons.StartupPage,
            partial(
                self._ui_handler.switch_modules,
                module=self._main_modules_stack,
            ),
        )
        self._configurator_module_0.module_connection(
            Buttons.StartupPage,
            partial(
                self._ui_handler.toggle_ui_visibility,
                uis=[self._configurator_ui, self._main_ui],
            ),
        )
