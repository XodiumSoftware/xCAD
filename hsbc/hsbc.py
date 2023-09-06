import datetime

from openpyxl import Workbook


class ExcelDataOrganizer:
    """ExcelDataOrganizer is a class that helps to organize data in Excel"""

    def __init__(self):
        """Initialize the class"""
        self.wb = Workbook()
        self.ws = self.wb.active

    def add_value_to_cell(self, cell, value):
        """Add value to a cell in the active worksheet"""
        self.ws[cell] = value

    def append_row(self, data):
        """Append a row to the active worksheet"""
        self.ws.append(data)

    def set_tab_properties(self, sheet_title, tab_color):
        """Set the name and tab color for the active worksheet"""
        self.ws.title = sheet_title
        self.ws.sheet_properties.tabColor = tab_color

    def save_workbook(self, filename):
        """Save the workbook to a file"""
        self.wb.save(filename)


if __name__ == "__main__":
    organizer = ExcelDataOrganizer()

    organizer.set_tab_properties("!ADMIN", "FF0000")

    organizer.add_value_to_cell("A1", 42)
    organizer.add_value_to_cell("A2", datetime.datetime.now())

    organizer.append_row([1, 2, 3])

    organizer.save_workbook("blanco_HSB_config.xlsx")
