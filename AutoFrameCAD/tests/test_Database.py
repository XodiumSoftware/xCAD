import unittest
from unittest.mock import patch

from AutoFrameCAD.Constants import BASE_DIR
from AutoFrameCAD.Database import Database


class TestDatabase(unittest.TestCase):
    def setUp(self):
        self.db_path = BASE_DIR / "tests" / "test.db"
        self.db_path.parent.mkdir(parents=True, exist_ok=True)
        self.db = Database(self.db_path)
        self.test_data = {
            "table1": [
                {"col1": "value1", "col2": 123},
                {"col1": "value2", "col2": 456},
            ],
            "table2": [{"col3": "value3", "col4": 789}],
        }

    def tearDown(self):
        self.db.__del__()

    def test_add_data(self):
        with patch("AFCUtils.import_json") as mock_import_json:
            mock_import_json.return_value = self.test_data
            self.db.add_data()

        self.assertEqual(
            self.db.get_data("table1"),
            [("value1", 123), ("value2", 456)],
        )
        self.assertEqual(
            self.db.get_data("table2"),
            [("value3", 789)],
        )

    def test_del_data(self):
        self.db.exec_sql(
            "INSERT INTO table1 (col1, col2) VALUES (?, ?)", ("value1", 123)
        )
        self.db.exec_sql(
            "INSERT INTO table1 (col1, col2) VALUES (?, ?)", ("value2", 456)
        )

        self.db.del_data("table1", id=1)

        self.assertEqual(
            self.db.get_data("table1"),
            [("value2", 456)],
        )

    def test_get_data(self):
        self.db.exec_sql(
            "INSERT INTO table1 (col1, col2) VALUES (?, ?)", ("value1", 123)
        )
        self.db.exec_sql(
            "INSERT INTO table1 (col1, col2) VALUES (?, ?)", ("value2", 456)
        )

        data = self.db.get_data("table1")

        self.assertEqual(
            data,
            [("value1", 123), ("value2", 456)],
        )


if __name__ == "__main__":
    unittest.main()
