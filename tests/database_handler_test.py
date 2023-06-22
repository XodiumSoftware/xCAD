from handlers.db_handler import DataBaseHandler

handler = DataBaseHandler()

DATA_TABLES = ["FRAME_DATA", "OBJECT_ASSEMBLY_DATA"]

# Insert data
data_to_insert = [[1, 2, 3, 4], [5, 6, 7, 8]]

for i, table_name in enumerate(DATA_TABLES):
    handler.insert_data(table_name, data_to_insert[i])

# Retrieve data
retrieved_data = handler.retrieve_data()
print(retrieved_data)  # Output: [[1, 2, 3, 4], [5, 6, 7, 8]]
