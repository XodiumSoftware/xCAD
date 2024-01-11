from tkinter import ttk as tkttk


class GridHandler:
    """A class used to represent a grid."""

    def __init__(self, grid: list) -> None:
        """Initialize the class.

        Args:
            grid (list): The grid to use.
        """
        self.grid = grid

    def setup_grid(self, container: tkttk.Frame) -> None:
        """Set up the grid in the container."""
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
                container.grid_columnconfigure(i, weight=self.grid[i][j])
                container.grid_rowconfigure(j, weight=self.grid[i][j])


class ContainerHandler:
    """A class used to represent a container."""

    def __init__(self, container: tkttk.Frame) -> None:
        """Initialize the class.

        Args:
            container (tkTk): The container to use.
        """
        self.container = container

    def set_grid(self, grid_handler: GridHandler) -> None:
        """Set a grid in the container."""
        grid_handler.setup_grid(self.container)
