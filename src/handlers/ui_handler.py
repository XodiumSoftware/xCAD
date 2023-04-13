from ui.main_ui import MainUI
from ui.tfcc_ui import TFCCUI

# FIXME: circular import


class ShowUIHandler:
    def __init__(self):
        self.tfccui_instance = TFCCUI()
        self.mainui_instance = MainUI()

    def open_ui_handler(self, index):
        if index == 0:
            self.mainui_instance.hide()
            self.tfccui_instance.show()
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
