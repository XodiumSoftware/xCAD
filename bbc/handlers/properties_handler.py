class PropertiesHandler:
    """Handle the properties."""

    @staticmethod
    def setup_init_object_properties():
        """Setup the initial item properties."""
        return {
            "General settings:": [
                {
                    "Name:": "SLS",
                    "Draw order:": 0,
                },
            ],
            "Dimension settings:": [
                {
                    "Length:": 38,
                    "Height:": 1000,
                    "Area:": None,
                    "Perimeter:": None,
                    "Rotation": 0,
                    "Scale": 1,
                },
            ],
            "Fill settings:": [
                {
                    "Fill:": True,
                    "Fill pattern:": "SolidPattern",
                    "Fill color:": "#ebd3b0",
                    "Fill opacity:": 1,
                },
            ],
            "Pen settings:": [
                {
                    "Pen style:": "SolidLine",
                    "Pen color:": "#ffffff",
                    "Pen thickness:": 5,
                },
            ],
        }
