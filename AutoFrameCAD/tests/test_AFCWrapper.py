import ctypes
import unittest
from unittest.mock import MagicMock

from AFCWrapper import Wrapper


class TestWrapper(unittest.TestCase):
    def setUp(self):
        self.wrapper = Wrapper()

    def test_cpp_function(self):
        self.wrapper.cpp_lib.cpp_function = MagicMock()

        self.wrapper.cpp_function()

        self.wrapper.cpp_lib.cpp_function.assert_called_once()

    def test_cpp_add(self):
        a, b = 5, 10
        expected_result = a + b

        result = self.wrapper.cpp_add(a, b)

        self.assertEqual(result, expected_result)

    def test_cpp_get_string(self):
        expected_result = 'Hello, World!'
        self.wrapper.cpp_lib.cpp_get_string = MagicMock(
            return_value=expected_result.encode('utf-8')
        )

        result = self.wrapper.cpp_get_string()

        self.assertEqual(result, expected_result)

    def test_cpp_print_string(self):
        string = 'Test string'
        self.wrapper.cpp_lib.cpp_print_string = MagicMock()

        self.wrapper.cpp_print_string(string)

        self.wrapper.cpp_lib.cpp_print_string.assert_called_once_with(
            ctypes.c_char_p(string.encode('utf-8'))
        )

    def test_cpp_set_callback(self):
        callback = MagicMock()
        self.wrapper.cpp_lib.cpp_set_callback = MagicMock()

        self.wrapper.cpp_set_callback(callback)

        self.wrapper.cpp_lib.cpp_set_callback.assert_called_once_with(
            self.wrapper.callback_func(callback)
        )


if __name__ == '__main__':
    unittest.main()
