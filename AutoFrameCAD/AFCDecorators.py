from typing import Any, Callable, Type


class ErrorHandler:
    """A class used to handle errors."""

    def __init__(self, *exceptions: Type[Exception]) -> None:
        """Initializes the error handler.

        Args:
            *exceptions (Type[Exception]): The exceptions to handle.
        """
        self.exceptions: tuple[Type[Exception], ...] = exceptions

    def __call__(self, func: Callable[..., Any]) -> Callable[..., Any]:
        """Makes the class callable.

        Args:
            func (Callable): The function to wrap.
        """

        def wrapper(*args: tuple[Any, ...], **kwargs: dict[str, Any]) -> Any:
            """The wrapper.

            Args:
                *args (tuple): The arguments.
                **kwargs (dict): The keyword arguments.
            """
            try:
                return func(*args, **kwargs)
            except self.exceptions as e:
                raise e

        return wrapper
