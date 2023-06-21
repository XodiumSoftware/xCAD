from constants import FRAME_DATA, OBJECT_ASSEMBLY_DATA

# Print the combined tables
TABLES = [
    (FRAME_DATA, "FRAME_DATA"),
    (OBJECT_ASSEMBLY_DATA, "OBJECT_ASSEMBLY_DATA"),
]
for table, table_name in TABLES:
    print(f"{table_name}:")
    print(table)
    print()
