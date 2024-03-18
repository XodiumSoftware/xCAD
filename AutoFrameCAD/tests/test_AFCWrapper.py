import ctypes
import unittest
from unittest.mock import MagicMock

from AFCWrapper import Wrapper


class TestWrapper(unittest.TestCase):
    def setUp(self):
        # Create an instance of the Wrapper class
        self.wrapper = Wrapper()

    def test_cpp_function(self):
        # Arrange
        self.wrapper.cpp_lib.cpp_function = MagicMock()

        # Act
        self.wrapper.cpp_function()

        # Assert
        self.wrapper.cpp_lib.cpp_function.assert_called_once()

    def test_cpp_add(self):
        # Arrange
        a = 5
        b = 10
        expected_result = a + b

        # Act
        result = self.wrapper.cpp_add(a, b)

        # Assert
        self.assertEqual(result, expected_result)

    def test_cpp_get_string(self):
        # Arrange
        expected_result = 'Hello, World!'
        self.wrapper.cpp_lib.cpp_get_string = MagicMock(
            return_value=expected_result.encode('utf-8')
        )

        # Act
        result = self.wrapper.cpp_get_string()

        # Assert
        self.assertEqual(result, expected_result)

    def test_cpp_print_string(self):
        # Arrange
        string = 'Test string'
        self.wrapper.cpp_lib.cpp_print_string = MagicMock()

        # Act
        self.wrapper.cpp_print_string(string)

        # Assert
        self.wrapper.cpp_lib.cpp_print_string.assert_called_once_with(
            ctypes.c_char_p(string.encode('utf-8'))
        )

    def test_cpp_set_callback(self):
        # Arrange
        callback = MagicMock()
        self.wrapper.cpp_lib.cpp_set_callback = MagicMock()

        # Act
        self.wrapper.cpp_set_callback(callback)

        # Assert
        self.wrapper.cpp_lib.cpp_set_callback.assert_called_once_with(
            self.wrapper.callback_func(callback)
        )


if __name__ == '__main__':
    unittest.main()
