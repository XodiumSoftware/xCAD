from AutoFrameCAD.AFCConstants import TIMBER_TYPES_DB_PATH
from AutoFrameCAD.AFCDatabase import Database


def test_database():
    """Test the Database class."""
    db = Database(TIMBER_TYPES_DB_PATH)

    table = 'test_table'
    data = [
        {'id': 0, 'name': 'Test', 'value': '123'},
        {'id': 1, 'name': 'Test2', 'value': '456'},
        {'id': 2, 'name': 'Test3', 'value': '789'},
    ]

    data_copy = [row.copy() for row in data]

    db.add_data(table, data_copy)

    result = db.get_data(table)

    assert result == data

    # db.__delete__(table)
