# constants.py

# ... (existing constants remain the same)

# Define the matrix data with support for nested containers
# Each element in module_matrix_pos can contain either a list of widgets
# or another set of "module_args" representing a nested container.
# For nested containers, specify the nested layout as a string.
MATRICES = [
    {
        "index": 1,
        "module_matrix_pos": [
            [  # Row 1
                [
                    "VBox",  # Module Layout
                    "Label",  # Module Type
                    1,  # Module Index
                    (0, 0, 0, 0),  # Margins (optional)
                    "AlignLeading",  # Alignment (optional)
                    None,  # Size Policy (optional)
                ],
                [  # Nested container with two widgets
                    [
                        "VBox",  # Nested Module Layout
                        [  # List of widgets in the nested container
                            [
                                "Label",  # Nested Module Type
                                2,  # Nested Module Index
                                (0, 0, 0, 0),  # Nested Margins (optional)
                                "AlignLeading",  # Nested Alignment (optional)
                                None,  # Nested Size Policy (optional)
                            ],
                            [
                                "Button",  # Nested Module Type
                                1,  # Nested Module Index
                                (0, 0, 0, 0),  # Nested Margins (optional)
                                "AlignLeading",  # Nested Alignment (optional)
                                None,  # Nested Size Policy (optional)
                            ],
                        ],
                        None,  # Nested alignment for the nested container (optional)
                        None,  # Nested size policy for the nested container (optional)
                    ],
                ],
            ],
            [  # Row 2
                [
                    "VBox",  # Module Layout
                    "SpinBox",  # Module Type
                    3,  # Module Index
                    (0, 0, 0, 0),  # Margins (optional)
                    "AlignLeading",  # Alignment (optional)
                    None,  # Size Policy (optional)
                ],
                [  # Another nested container with a widget
                    [
                        "HBox",  # Nested Module Layout
                        [  # List of widgets in the nested container
                            [
                                "Checkbox",  # Nested Module Type
                                1,  # Nested Module Index
                                (0, 0, 0, 0),  # Nested Margins (optional)
                                "AlignLeading",  # Nested Alignment (optional)
                                None,  # Nested Size Policy (optional)
                            ],
                        ],
                        None,  # Nested alignment for the nested container (optional)
                        None,  # Nested size policy for the nested container (optional)
                    ],
                ],
            ],
        ],
    },
    # Add more matrices as needed...
]
