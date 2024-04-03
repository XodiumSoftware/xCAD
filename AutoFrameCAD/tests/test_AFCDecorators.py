import unittest

from AFCDecorators import ErrorHandler


class TestErrorHandler(unittest.TestCase):
    @ErrorHandler(ValueError)
    def divide_by_zero(self):
        return 1 / 0

    @ErrorHandler(ValueError, TypeError)
    def convert_string_to_int(self):
        return int('not_an_integer')

    @ErrorHandler(ValueError, TypeError)
    def divide_by_zero_again(self):
        return 1 / 0

    def test_error_handler(self):
        with self.assertRaises(ValueError):
            self.divide_by_zero()

    def test_error_handler_value_error(self):
        with self.assertRaises(ValueError):
            self.convert_string_to_int()

    def test_error_handler_type_error(self):
        with self.assertRaises(TypeError):
            self.divide_by_zero_again()


if __name__ == '__main__':
    unittest.main()
