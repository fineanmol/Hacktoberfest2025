"""
Unit tests for gcd.py
"""
import unittest
import sys
import os

# Add the parent directory to the path so we can import gcd
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from gcd import gcd


class TestGCD(unittest.TestCase):
    """Test cases for the GCD function"""
    
    def test_basic_gcd(self):
        """Test basic GCD calculations"""
        self.assertEqual(gcd(12, 8), 4)
        self.assertEqual(gcd(15, 25), 5)
        self.assertEqual(gcd(7, 13), 1)  # Prime numbers
        self.assertEqual(gcd(100, 25), 25)
    
    def test_negative_numbers(self):
        """Test GCD with negative numbers"""
        self.assertEqual(gcd(-12, 8), 4)
        self.assertEqual(gcd(12, -8), 4)
        self.assertEqual(gcd(-12, -8), 4)
    
    def test_zero_cases(self):
        """Test GCD with zero"""
        self.assertEqual(gcd(0, 5), 5)
        self.assertEqual(gcd(5, 0), 5)
    
    def test_same_numbers(self):
        """Test GCD with same numbers"""
        self.assertEqual(gcd(10, 10), 10)
    
    def test_both_zero_error(self):
        """Test that both numbers being zero raises an error"""
        with self.assertRaises(ValueError):
            gcd(0, 0)
    
    def test_invalid_input_types(self):
        """Test that non-integer inputs raise TypeError"""
        with self.assertRaises(TypeError):
            gcd(10.5, 5)
        
        with self.assertRaises(TypeError):
            gcd(10, "5")
        
        with self.assertRaises(TypeError):
            gcd([10], 5)
    
    def test_large_numbers(self):
        """Test GCD with large numbers"""
        self.assertEqual(gcd(123456789, 987654321), 9)
        self.assertEqual(gcd(2**20, 2**15), 2**15)
    
    def test_edge_cases(self):
        """Test edge cases"""
        self.assertEqual(gcd(1, 1), 1)
        self.assertEqual(gcd(1, 100), 1)
        self.assertEqual(gcd(100, 1), 1)


if __name__ == '__main__':
    unittest.main()
