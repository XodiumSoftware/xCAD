from PySide6.QtWidgets import QApplication

from ui.tfcc_ui import TFCCUI


class UIHandler:
    def open_ui_handler(self, index):
        mainui_instance = QApplication.activeWindow()
        tfccui_instance = TFCCUI()

        if index == 0:
            mainui_instance.close()
            tfccui_instance.show()
        # elif index == 1:
        #     self.close()
        #     self.tfccui_instance.show()
        # etc etc....
        # TODO: instead of putting tfccui_instance,
        # when other ui classes will be created
        # you have to put those classes inside the __init__
        # (e.g. self.calculations_instance = CalcUi())
        # and then check for the index in this function
        # and open it here
