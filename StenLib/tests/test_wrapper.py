import ctypes
import unittest

from AutoFrameCAD.constants import UTILS_LIB_FILE
from StenLib import Utils


class TestWrapper(unittest.TestCase):
    """A class to test the Wrapper class"""

    def setUp(self) -> None:
        """Sets up the test"""
        self.wrapper = Utils.wrap(UTILS_LIB_FILE)
        self.arr = list(range(1, 6))
        self.arr_type = ctypes.c_int * len(self.arr)
        self.arr_c = self.arr_type(*self.arr)

    def tearDown(self) -> None:
        """Clean up after the test"""
        del self.wrapper
        del self.arr_c

    def test_factorial(self) -> None:
        """Tests the factorial function"""
        self.assertIs(self.wrapper.factorial(5), 120)

    def test_sumArray(self) -> None:
        """Tests the sumArray function"""
        self.assertIs(self.wrapper.sumArray(self.arr_c, len(self.arr)), 15)

    def test_isPalindrome(self) -> None:
        """Tests the isPalindrome function"""
        self.assertTrue(self.wrapper.isPalindrome(b"racecar"))

    def test_isPrime(self) -> None:
        """Tests the isPrime function"""
        self.assertTrue(self.wrapper.isPrime(7))

    def test_maxArray(self) -> None:
        """Tests the maxArray function"""
        self.assertIs(self.wrapper.maxArray(self.arr_c, len(self.arr)), 5)

    def test_minArray(self) -> None:
        """Tests the minArray function"""
        self.assertIs(self.wrapper.minArray(self.arr_c, len(self.arr)), 1)
