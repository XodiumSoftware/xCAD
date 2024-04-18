import ctypes
import unittest

from AutoFrameCAD.wrapper import Wrapper


class TestWrapper(unittest.TestCase):
    """A class to test the Wrapper class"""

    def setUp(self) -> None:
        """Initializes the Wrapper object and the test arrays"""
        self.wrapper = Wrapper()
        self.arr = [1, 2, 3, 4, 5]
        self.arr_type = ctypes.c_int * len(self.arr)
        self.arr_c = self.arr_type(*self.arr)

    def test_factorial(self) -> None:
        """Tests the factorial function"""
        self.assertEqual(self.wrapper.functions["factorial"](5), 120)

    def test_sumArray(self) -> None:
        """Tests the sumArray function"""
        self.assertEqual(
            self.wrapper.functions["sumArray"](self.arr_c, len(self.arr)), 15
        )

    def test_isPalindrome(self) -> None:
        """Tests the isPalindrome function"""
        self.assertTrue(self.wrapper.functions["isPalindrome"](b"racecar"))

    def test_isPrime(self) -> None:
        """Tests the isPrime function"""
        self.assertTrue(self.wrapper.functions["isPrime"](7))

    def test_maxArray(self) -> None:
        """Tests the maxArray function"""
        self.assertEqual(
            self.wrapper.functions["maxArray"](self.arr_c, len(self.arr)), 5
        )

    def test_minArray(self) -> None:
        """Tests the minArray function"""
        self.assertEqual(
            self.wrapper.functions["minArray"](self.arr_c, len(self.arr)), 1
        )
