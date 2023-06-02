from PySide6.QtWidgets import QGridLayout, QLabel, QPushButton, QWidget

# Constants
LABEL_TEXT = "This is a modular widget."
BUTTON_TEXT = "Click me!"
BUTTON_CLICKED_MSG = "Button clicked."


class ModularLayout(QGridLayout):
    def __init__(self):
        """
        Create a modular layout with a label and a button.
        """
        super().__init__()

        # Add widgets to the layout
        label = ModularLabel(LABEL_TEXT)
        self.addWidget(label, 0, 0)

        button = ModularButton(BUTTON_TEXT)
        self.addWidget(button, 1, 0)


class ModularLabel(QLabel):
    def __init__(self, text: str, parent=None):
        """
        Create a modular label with the given text.
        """
        super().__init__(text, parent)

        # Customize the label's appearance or behavior as needed


class ModularButton(QPushButton):
    def __init__(self, text: str, parent=None):
        """
        Create a modular button with the given text.
        """
        super().__init__(text, parent)

        # Connect the button's clicked signal to the on_button_clicked slot
        self.clicked.connect(self.on_button_clicked)

    def on_button_clicked(self):
        """
        Slot for the button's clicked signal.
        """
        print(BUTTON_CLICKED_MSG)


class ModularWidget(QWidget):
    def __init__(self, parent=None):
        """
        Create a modular widget with a modular layout.
        """
        super().__init__(parent)

        # Create the main layout
        layout = ModularLayout()

        # Set the layout for the widget
        self.setLayout(layout)


# Example usage
if __name__ == "__main__":
    from PySide6.QtWidgets import QApplication

    app = QApplication([])

    # Create an instance of the modular widget
    widget = ModularWidget()
    widget.show()

    app.exec()
