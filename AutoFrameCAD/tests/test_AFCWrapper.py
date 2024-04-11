import ctypes
import unittest

from AFCWrapper import Wrapper


class TestWrapper(unittest.TestCase):
    def setUp(self):
        self.wrapper = Wrapper()

    def tearDown(self):
        self.wrapper = None

    def test_factorial(self):
        result = self.wrapper.factorial(5)  # type: ignore
        self.assertEqual(result, 120)

    def test_sum_array(self):
        array = (ctypes.c_int * 5)(1, 2, 3, 4, 5)
        result = self.wrapper.sumArray(array, 5)  # type: ignore
        self.assertEqual(result, 15)

    def test_is_palindrome(self):
        result = self.wrapper.isPalindrome(b"racecar")  # type: ignore
        self.assertTrue(result)

    def test_is_prime(self):
        result = self.wrapper.isPrime(7)  # type: ignore
        self.assertTrue(result)

    def test_max_array(self):
        array = (ctypes.c_int * 5)(1, 2, 3, 4, 5)
        result = self.wrapper.maxArray(array, 5)  # type: ignore
        self.assertEqual(result, 5)

    def test_min_array(self):
        array = (ctypes.c_int * 5)(1, 2, 3, 4, 5)
        result = self.wrapper.minArray(array, 5)  # type: ignore
        self.assertEqual(result, 1)

    def test_reverse_string(self):
        result = self.wrapper.reverseString(b"hello")  # type: ignore
        self.assertEqual(result, b"olleh")


if __name__ == "__main__":
    unittest.main()
