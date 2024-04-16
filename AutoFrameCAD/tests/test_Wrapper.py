import ctypes
import unittest

from AutoFrameCAD.Wrapper import Wrapper


class TestWrapper(unittest.TestCase):
    def setUp(self):
        self.wrapper = Wrapper()
        self.arr = [1, 2, 3, 4, 5]
        self.arr_type = ctypes.c_int * len(self.arr)
        self.arr_c = self.arr_type(*self.arr)

    def test_factorial(self):
        self.assertEqual(self.wrapper.functions["factorial"](5), 120)

    def test_sumArray(self):
        self.assertEqual(
            self.wrapper.functions["sumArray"](self.arr_c, len(self.arr)), 15
        )

    def test_isPalindrome(self):
        self.assertTrue(self.wrapper.functions["isPalindrome"](b"racecar"))

    def test_isPrime(self):
        self.assertTrue(self.wrapper.functions["isPrime"](7))

    def test_maxArray(self):
        self.assertEqual(
            self.wrapper.functions["maxArray"](self.arr_c, len(self.arr)), 5
        )

    def test_minArray(self):
        self.assertEqual(
            self.wrapper.functions["minArray"](self.arr_c, len(self.arr)), 1
        )


if __name__ == "__main__":
    unittest.main()
