from AFCConstants import TIMBER_TYPES_DB_PATH
from AFCDatabase import Database


def test_database():
    """Test the Database class."""
    db = Database(TIMBER_TYPES_DB_PATH)

    table = 'test_table'
    data = [{'id': 1, 'name': 'Test', 'value': '123'}]

    db.add_data(table, data)

    result = db.get_data(table)

    assert result == data

    db.__delete__(table)
