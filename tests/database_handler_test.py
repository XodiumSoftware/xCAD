from handlers.db_handler import DataBaseHandler


class DataBaseHandlerTest:
    def __init__(self):
        """
        This class is used to test the DataBaseHandler class.
        """
        self.handler = DataBaseHandler()
        self.DATA_TABLES = ["FRAME_DATA", "OBJECT_ASSEMBLY_DATA"]

    def process_data(self):
        """
        This method is used to test the DataBaseHandler class.
        """
        data_to_insert = [[1, 2, 3, 4], [5, 6, 7, 8]]
        retrieved_data = []

        for i, table_name in enumerate(self.DATA_TABLES):
            self.handler.save_table_data(table_name, data_to_insert[i])
            table_data = self.handler.get_table_data(table_name)
            retrieved_data.append(table_data)

        return retrieved_data


def run():
    processor = DataBaseHandlerTest()
    processed_data = processor.process_data()
    print(processed_data)  # Output: [[1, 2, 3, 4], [5, 6, 7, 8]]


run()
