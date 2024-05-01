"""This module contains unit tests for the Wrapper class."""

import ctypes
import unittest

from autoframecad.__config__ import UTILS_LIB_FILE
from stenlib import Utils


class TestWrapper(unittest.TestCase):
    """A class to test the Wrapper class."""

    def setUp(self: "TestWrapper") -> None:
        """Sets up the test."""
        self.wrapper = Utils.wrap(UTILS_LIB_FILE)
        self.arr = list(range(1, 6))
        self.arr_type = ctypes.c_int * len(self.arr)
        self.arr_c = self.arr_type(*self.arr)

    def test_factorial(self: "TestWrapper") -> None:
        """Tests the factorial function."""
        expected_result = 120
        if self.wrapper.factorial(5) != expected_result:
            raise AssertionError

    def test_sumarray(self: "TestWrapper") -> None:
        """Tests the sumArray function."""
        expected_result = 15
        if self.wrapper.sumArray(self.arr_c, len(self.arr)) != expected_result:
            raise AssertionError

    def test_ispalindrome(self: "TestWrapper") -> None:
        """Tests the isPalindrome function."""
        if not self.wrapper.isPalindrome(b"racecar"):
            raise AssertionError

    def test_isprime(self: "TestWrapper") -> None:
        """Tests the isPrime function."""
        if not self.wrapper.isPrime(7):
            raise AssertionError

    def test_maxarray(self: "TestWrapper") -> None:
        """Tests the maxArray function."""
        expected_result = 5
        if self.wrapper.maxArray(self.arr_c, len(self.arr)) != expected_result:
            raise AssertionError

    def test_minarray(self: "TestWrapper") -> None:
        """Tests the minArray function."""
        expected_result = 1
        if self.wrapper.minArray(self.arr_c, len(self.arr)) != expected_result:
            raise AssertionError
