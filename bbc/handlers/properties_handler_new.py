from typing import Any, Dict, List


class PropertiesHandler:
    @staticmethod
    def setup_init_object_properties(
        object_type: str,
    ) -> Dict[str, List[Dict[str, Any]]]:
        object_properties = {
            "Line": {
                "General settings:": [
                    {
                        "Name:": "Line",
                    },
                ],
                "Dimension settings:": [
                    {
                        "Start point:": (0, 0),
                        "End point:": (100, 100),
                        "Length:": None,
                    }
                ],
            },
            "Polyline": {
                "General settings:": [
                    {
                        "Name:": "Polyline",
                    },
                ],
                "Dimension settings:": [
                    {
                        "Vertices:": [],
                        "Length:": None,
                        "Area:": None,
                    }
                ],
            },
            "Circle": {
                "General settings:": [
                    {
                        "Name:": "Circle",
                    },
                ],
                "Dimension settings:": [
                    {
                        "Center:": (0, 0),
                        "Radius:": 10,
                        "Circumference:": None,
                        "Area:": None,
                    }
                ],
            },
            "Arc": {
                "General settings:": [
                    {
                        "Name:": "Arc",
                    },
                ],
                "Dimension settings:": [
                    {
                        "Center:": (0, 0),
                        "Radius:": 10,
                        "Start angle:": 0,
                        "End angle:": 90,
                        "Arc length:": None,
                        "Area:": None,
                    }
                ],
            },
            "Ellipse": {
                "General settings:": [
                    {
                        "Name:": "Ellipse",
                    },
                ],
                "Dimension settings:": [
                    {
                        "Center:": (0, 0),
                        "Major axis:": 20,
                        "Minor axis:": 10,
                        "Area:": None,
                    }
                ],
            },
            "Hatch": {
                "General settings:": [
                    {
                        "Name:": "Hatch",
                    },
                ],
                "Fill settings:": [
                    {
                        "Fill:": True,
                        "Fill pattern:": "SolidPattern",
                        "Fill color:": "#ebd3b0",
                        "Fill opacity:": 1,
                    }
                ],
            },
        }

        return object_properties.get(
            object_type,
            {"error": [{"message": f"Unsupported object type: {object_type}"}]},
        )
