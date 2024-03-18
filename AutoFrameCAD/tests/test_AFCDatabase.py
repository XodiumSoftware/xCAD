import unittest
from pathlib import Path
from unittest.mock import patch

from AFCDatabase import Database


class TestDatabase(unittest.TestCase):
    def setUp(self):
        self.db_path = Path('/path/to/database.db')
        self.db = Database(self.db_path)

    def tearDown(self):
        self.db.__del__()

    def test_add_data(self):
        # Mock import_json function
        with patch('AFCUtils.import_json') as mock_import_json:
            mock_import_json.return_value = {
                'table1': [
                    {'col1': 'value1', 'col2': 123},
                    {'col1': 'value2', 'col2': 456},
                ],
                'table2': [{'col3': 'value3', 'col4': 789}],
            }
            self.db.add_data()

        # Assert that tables are created and data is inserted
        self.assertEqual(
            self.db.get_data('table1'),
            [('value1', 123), ('value2', 456)],
        )
        self.assertEqual(
            self.db.get_data('table2'),
            [('value3', 789)],
        )

    def test_del_data(self):
        # Insert test data
        self.db.exec_sql(
            'INSERT INTO table1 (col1, col2) VALUES (?, ?)', ('value1', 123)
        )
        self.db.exec_sql(
            'INSERT INTO table1 (col1, col2) VALUES (?, ?)', ('value2', 456)
        )

        # Delete data
        self.db.del_data('table1', id=1)

        # Assert that data is deleted
        self.assertEqual(
            self.db.get_data('table1'),
            [('value2', 456)],
        )

    def test_get_data(self):
        # Insert test data
        self.db.exec_sql(
            'INSERT INTO table1 (col1, col2) VALUES (?, ?)', ('value1', 123)
        )
        self.db.exec_sql(
            'INSERT INTO table1 (col1, col2) VALUES (?, ?)', ('value2', 456)
        )

        # Get data
        data = self.db.get_data('table1')

        # Assert that data is retrieved correctly
        self.assertEqual(
            data,
            [('value1', 123), ('value2', 456)],
        )


if __name__ == '__main__':
    unittest.main()
