# ====================================================================================================
# Editable: 0 = False, 1 = True
# ====================================================================================================
# Cell Types:
# 0: Label
# 1: Button
# 2: Input Box
# 3: Double Spin Box
# 4: Dropdown list
# 5: Checkbox
# Add more cell types here as needed
# ====================================================================================================

import pandas as pd
from PySide6.QtGui import Qt

FILL_PATTERNS = {
    Qt.BrushStyle.SolidPattern,  # Solid fill pattern
    Qt.BrushStyle.Dense1Pattern,  # Dense fill pattern 1
    Qt.BrushStyle.Dense2Pattern,  # Dense fill pattern 2
}

PEN_STYLES = {
    Qt.PenStyle.SolidLine,  # Solid line style
    Qt.PenStyle.DashLine,  # Dashed line style
    Qt.PenStyle.DotLine,  # Dotted line style
}

TABLES = {
    "TABLE_0": pd.DataFrame(
        columns=[
            "Col_0",
            "Flag_0",
            "Col_1",
            "Flag_1",
        ],
        data=[
            (
                "Structure",
                "[False,0]",
                "Select",
                "[False,1]",
            ),
            (
                "Length (mm)",
                "[False,0]",
                6000,
                "[True,3]",
            ),
            (
                "Height (mm)",
                "[False,0]",
                3000,
                "[True,3]",
            ),
            (
                "Area (m2)",
                "[False,0]",
                None,
                "[False,2]",
            ),
            (
                "Perimeter (m1)",
                "[False,0]",
                None,
                "[False,2]",
            ),
        ],
    ),
    "TABLE_1": pd.DataFrame(
        columns=[
            "Col_0",
            "Flag_0",
            "Col_1",
            "Flag_1",
        ],
        data=[
            (
                "Thickness",
                "[False,0]",
                60,
                "[True,2]",
            ),
            (
                "Pen color",
                "[False,0]",
                "255, 255, 255",
                "[True,2]",
            ),
            (
                "Pen thickness",
                "[False,0]",
                1,
                "[True,2]",
            ),
            (
                "Pen style",
                "[False,0]",
                PEN_STYLES,
                "[True,4]",
            ),
            (
                "Fill pattern",
                "[False,0]",
                FILL_PATTERNS,
                "[True,4]",
            ),
            (
                "Fill pattern scale",
                "[False,0]",
                1,
                "[True,2]",
            ),
            (
                "Fill pattern angle",
                "[False,0]",
                0,
                "[True,2]",
            ),
            (
                "Fill",
                "[False,0]",
                True,
                "[True,5]",
            ),
            (
                "Fill color",
                "[False,0]",
                "255, 0, 0",
                "[True,2]",
            ),
            (
                "Fill opacity",
                "[False,0]",
                0.5,
                "[True,2]",
            ),
        ],
    ),
    # Add more tables here as needed
}


# Print the combined tables
for table_name, table_data in TABLES.items():
    print(f"{table_name}:")
    print(table_data)
    print()
