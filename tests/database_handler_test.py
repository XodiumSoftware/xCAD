from handlers.db_handler import DataBaseHandler

handler = DataBaseHandler()

# Insert data
data_0 = [1, 2, 3, 4]
data_1 = [5, 6, 7, 8]

handler.insert_data("FRAME_DATA", data_0)
handler.insert_data("OBJECT_ASSEMBLY_DATA", data_1)

# Retrieve data
retrieved_data = handler.retrieve_data(["FRAME_DATA", "OBJECT_ASSEMBLY_DATA"])
print(retrieved_data)  # Output: [[1, 2, 3, 4], [5, 6, 7, 8]]
