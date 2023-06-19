import json
import sqlite3

import pandas as pd

# ====================================================================================================
# Group Index [0, 1, 2, 3, etc.]:
# ====================================================================================================
# Editable: 0 = False, 1 = True
# ====================================================================================================
# Cell Types:
# 0: Label
# 1: Button
# 2: Input Box
# 3: Double Spin Box
# 4: Dropdown list
# Add more cell types here as needed
# ====================================================================================================


def convert_values_to_string(value):
    if isinstance(value, list):
        return json.dumps(value)
    return value


tables = pd.DataFrame(
    columns=[
        "Col_0",
        "Flags_0",
        "Col_1",
        "Flags_1",
    ]
)

tables.loc[0] = [
    ["Structure"],  # Col_0
    [0, False, 0],  # Flags_0
    ["Select"],  # Col_1
    [0, True, 1],  # Flags_1
]

tables.loc[1] = [
    ["Length (mm)"],
    [0, False, 0],
    [6000],
    [0, True, 3],
]

tables.loc[2] = [
    ["Height (mm)"],
    [0, False, 0],
    [3000],
    [0, True, 3],
]

tables.loc[3] = [
    ["Area (m2)"],
    [1, False, 0],
    [(tables.loc[1, "Col_1"][0] * tables.loc[2, "Col_1"][0]) / 10**6],
    [1, False, 0],
]

tables.loc[4] = [
    ["Perimeter (m1)"],
    [1, False, 0],
    [(tables.loc[1, "Col_1"][0] + tables.loc[2, "Col_1"][0]) * 2 / 10**3],
    [1, False, 0],
]

tables["Col_1"] = tables["Col_1"].apply(convert_values_to_string)

conn = sqlite3.connect("database.sqlite")

cursor = conn.cursor()
cursor.execute("DROP TABLE IF EXISTS Tables")
cursor.execute(
    """
    CREATE TABLE Tables (
        Col_0 TEXT,
        Flags_0 TEXT,
        Col_1 TEXT,
        Flags_1 TEXT
    )
    """
)

data = tables.to_dict(orient="records")
cursor.executemany(
    """
    INSERT INTO Tables (Col_0, Flags_0, Col_1, Flags_1)
    VALUES (?, ?, ?, ?)
    """,
    [(d["Col_0"], d["Flags_0"], d["Col_1"], d["Flags_1"]) for d in data],
)

conn.commit()
conn.close()

print(tables)
