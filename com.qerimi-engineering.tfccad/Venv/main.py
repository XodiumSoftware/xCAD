# Standard library imports
import sys
#sys.path.append("Venv/window_frames")

# Third-party imports
from PyQt6.QtWidgets import QApplication

# Internal module imports
from Venv.window_frames.main_window import TfccadMainWindow

# `if __name__ == '__main__':` is a conditional statement that checks if the current script is being
# run as the main program. If it is, then the code inside the block will be executed. This is commonly
# used to prevent code from being executed when the script is imported as a module into another
# program.
if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = TfccadMainWindow()
    main_window.show()
    sys.exit(app.exec())
