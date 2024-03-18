import unittest

from AFCDecorators import ErrorHandler


class TestErrorHandler(unittest.TestCase):
    def test_error_handler(self):
        # Define a function that raises an exception
        @ErrorHandler(ValueError)
        def divide_by_zero():
            return 1 / 0

        # Assert that the exception is raised
        with self.assertRaises(ValueError):
            divide_by_zero()

    def test_error_handler_multiple_exceptions(self):
        # Define a function that raises multiple exceptions
        @ErrorHandler(ValueError, TypeError)
        def divide_by_zero_or_convert_string_to_int():
            try:
                return int('not_an_integer')
            except ValueError:
                return 1 / 0

        # Assert that the exceptions are raised
        with self.assertRaises(ValueError):
            divide_by_zero_or_convert_string_to_int()

        with self.assertRaises(TypeError):
            divide_by_zero_or_convert_string_to_int()


if __name__ == '__main__':
    unittest.main()
