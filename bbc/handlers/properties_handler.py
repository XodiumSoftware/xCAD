from PySide6.QtCore import Qt


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

    @staticmethod
    def setup_pen_styles(pen_style):
        """Setup the pen styles."""
        pen_styles = {
            "NoPen": Qt.PenStyle.NoPen,
            "SolidLine": Qt.PenStyle.SolidLine,
            "DashLine": Qt.PenStyle.DashLine,
            "DotLine": Qt.PenStyle.DotLine,
            "DashDotLine": Qt.PenStyle.DashDotLine,
            "DashDotDotLine": Qt.PenStyle.DashDotDotLine,
            "CustomDashLine": Qt.PenStyle.CustomDashLine,
        }
        return pen_styles.get(pen_style, Qt.PenStyle.SolidLine)

    @staticmethod
    def setup_pen_cap_styles(pen_cap_style):
        """Setup the pen cap styles."""
        pen_cap_styles = {
            "FlatCap": Qt.PenCapStyle.FlatCap,
            "SquareCap": Qt.PenCapStyle.SquareCap,
            "RoundCap": Qt.PenCapStyle.RoundCap,
        }
        return pen_cap_styles.get(pen_cap_style, Qt.PenCapStyle.FlatCap)

    @staticmethod
    def setup_pen_join_styles(pen_join_style):
        """Setup the pen join styles."""
        pen_join_styles = {
            "MiterJoin": Qt.PenJoinStyle.MiterJoin,
            "BevelJoin": Qt.PenJoinStyle.BevelJoin,
            "RoundJoin": Qt.PenJoinStyle.RoundJoin,
            "SvgMiterJoin": Qt.PenJoinStyle.SvgMiterJoin,
        }
        return pen_join_styles.get(pen_join_style, Qt.PenJoinStyle.MiterJoin)

    @staticmethod
    def setup_fill_patterns(fill_pattern):
        """Setup the fill patterns."""
        fill_patterns = {
            "NoBrush": Qt.BrushStyle.NoBrush,
            "SolidPattern": Qt.BrushStyle.SolidPattern,
            "Dense1Pattern": Qt.BrushStyle.Dense1Pattern,
            "Dense2Pattern": Qt.BrushStyle.Dense2Pattern,
            "Dense3Pattern": Qt.BrushStyle.Dense3Pattern,
            "Dense4Pattern": Qt.BrushStyle.Dense4Pattern,
            "Dense5Pattern": Qt.BrushStyle.Dense5Pattern,
            "Dense6Pattern": Qt.BrushStyle.Dense6Pattern,
            "Dense7Pattern": Qt.BrushStyle.Dense7Pattern,
            "HorPattern": Qt.BrushStyle.HorPattern,
            "VerPattern": Qt.BrushStyle.VerPattern,
            "CrossPattern": Qt.BrushStyle.CrossPattern,
            "BDiagPattern": Qt.BrushStyle.BDiagPattern,
            "FDiagPattern": Qt.BrushStyle.FDiagPattern,
            "DiagCrossPattern": Qt.BrushStyle.DiagCrossPattern,
            "LinearGradientPattern": Qt.BrushStyle.LinearGradientPattern,
            "ConicalGradientPattern": Qt.BrushStyle.ConicalGradientPattern,
            "RadialGradientPattern": Qt.BrushStyle.RadialGradientPattern,
            "TexturePattern": Qt.BrushStyle.TexturePattern,
        }
        return fill_patterns.get(fill_pattern, Qt.BrushStyle.SolidPattern)
