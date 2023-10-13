from typing import Optional, Tuple

from PySide6.QtWidgets import QWidget


class ModuleUtils:
    """A class that contains core methods."""

    @staticmethod
    def margins(
        parent: QWidget, margins: Optional[Tuple[int, int, int, int]] = None
    ) -> Tuple[int, int, int, int]:
        """
        Initialize the margins with a specified margins.

        Args:
            margins (Tuple[int, int, int, int]): Margins for a layout.
                Default is parent's margins.

        Returns:
            Tuple[int, int, int, int]: A tuple of margins.
        """
        if (
            margins is not None
            and all(isinstance(i, int) for i in margins)
            and len(margins) == 4
        ):
            return margins

        pmargins = parent.contentsMargins()
        return (pmargins.left(), pmargins.top(), pmargins.right(), pmargins.bottom())
