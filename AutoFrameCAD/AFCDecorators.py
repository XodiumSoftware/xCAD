import logging
from typing import Any, Callable, Type


class ErrorHandler:
    """A class used to handle errors."""

    def __init__(self, *exceptions: Type[Exception], msg: str = '') -> None:
        """Initializes the error handler.

        Args:
            *exceptions (Type[Exception]): The exceptions to handle.
            msg (str): The message to display when an error occurs.
        """
        self.exceptions: tuple[Type[Exception], ...] = exceptions
        self.msg: str = msg

    def __call__(self, func: Callable[..., Any]) -> Callable[..., Any]:
        """Makes the class callable.

        Args:
            func (Callable): The function to wrap.
        """
        return self._wrapper(func)

    def _wrapper(
        self,
        func: Callable[..., Any],
        *args: tuple[Any, ...],
        **kwargs: dict[str, Any],
    ) -> Any:
        """The wrapper.

        Args:
            func (Callable): The function to wrap.
            *args (tuple): The arguments.
            **kwargs (dict): The keyword arguments.
        """
        try:
            return func(*args, **kwargs)
        except self.exceptions as e:
            logging.error(f'{self.msg} {str(e)}')
            raise e
