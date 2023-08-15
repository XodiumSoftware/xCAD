class PropertiesHandler:
    """Handle the properties."""

    @staticmethod
    def setup_init_item_properties():
        """Setup the initial item properties."""
        return {
            "General settings:": [
                {
                    "Name:": "SLS",
                },
            ],
            "Dimension settings:": [
                {
                    "Length:": 38,
                    "Height:": 1000,
                    "Area:": None,
                    "Perimeter:": None,
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
