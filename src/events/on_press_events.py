from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QWidget


# This is a class for handling events that occur when a button is pressed in a PyQt5 GUI application.
class OnPressEvents(QWidget):

    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        if event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q:
            self.close()

        '''try:
            from ui.main_ui import MainUi
            from ui.tfcc_ui import TFCCUi
        except ImportError as e:
            print(e)
        if MainUi and (event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q):
            self.close()
        if TFCCUi and (event.key() == Qt.Key.Key_Escape or (event.key() == Qt.Key.Key_Q and event.modifiers() == Qt.KeyboardModifier.ControlModifier)):
            # TODO: search line above for explanation on modifier
            on_back_button_pressed()'''
        
        '''if event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q:
            if MainUi:
                pass
            else:
                pass'''