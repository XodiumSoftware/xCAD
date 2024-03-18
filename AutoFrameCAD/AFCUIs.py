from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCHandlers import UIHandler as AFCUIHandler
from AFCUtils import Utils as AFCUtils


class PrimaryUI(AFCUIHandler):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        data = AFCUIDataclass()

        self.title(data.PRIMARY.TITLE)
        self.theme(data.PRIMARY.THEME)
        self.visible(data.PRIMARY.VISIBILITY)
        self.resizable(data.PRIMARY.RESIZABLE, data.PRIMARY.RESIZABLE)
        # NOTE: Adjust when tk 8.7/9.0 is released,
        # since it will have native svg support.
        self.iconphoto(
            data.PRIMARY.ICON, AFCUtils.svg2png((data.PRIMARY.ICON_PATH))
        )
        self.geometry(f'{data.PRIMARY.GEOM_X}x{data.PRIMARY.GEOM_Y}')
        self.minsize(data.PRIMARY.GEOM_X, data.PRIMARY.GEOM_Y)
        self.events(data.PRIMARY.EVENTS)
        self.matrix(data.PRIMARY.MATRIX)
