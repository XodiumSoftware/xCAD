import sqlite3

from constants import *
from PySide6.QtCore import QObject, Signal


class InputHandler(QObject):
    """
    Handles the input.
    """

    input_received = Signal(object)

    def __init__(self):
        """
        Initializes the input handler.
        """
        super().__init__()
        if not os.path.exists(DB_DIR):
            os.makedirs(DB_DIR)
        self.db_conn = sqlite3.connect(str(DB_FILE))
        self.db_cursor = self.db_conn.cursor()
        self.db_cursor.execute(CREATE_TABLE_SQL)
        self.db_conn.commit()

    def handle_input(self, input_data):
        """
        Handles the input.
        """
        # Save the input to the database
        input_type = type(input_data).__name__
        self.db_cursor.execute(INSERT_INPUT_SQL, (input_type, str(input_data)))
        self.db_conn.commit()
        # Emit the input_received signal
        self.input_received.emit(input_data)
