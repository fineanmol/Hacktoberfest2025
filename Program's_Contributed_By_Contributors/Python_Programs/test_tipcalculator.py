import unittest
from decimal import Decimal
from Tipcalculator import TipCalculator

class TestTipCalculator(unittest.TestCase):
    def setUp(self):
        self.calculator = TipCalculator()

    def test_calculate_tip(self):
        # Test basic tip calculation
        result = self.calculator.calculate_tip(Decimal('100.00'), Decimal('10'), 1)
        self.assertEqual(result['tip_amount'], '₹10.00')
        self.assertEqual(result['total_amount'], '₹110.00')

    def test_split_bill(self):
        # Test bill splitting
        result = self.calculator.calculate_tip(Decimal('100.00'), Decimal('20'), 4)
        self.assertEqual(result['per_person'], '₹30.00')

    def test_currency_formatting(self):
        # Test different currency formats
        self.calculator.set_currency('USD')
        result = self.calculator.calculate_tip(Decimal('50.00'), Decimal('15'), 1)
        self.assertTrue(result['bill_amount'].startswith('$'))

    def test_invalid_inputs(self):
        # Test negative bill amount
        with self.assertRaises(ValueError):
            self.calculator.calculate_tip(Decimal('-100.00'), Decimal('10'), 1)

        # Test negative tip percentage
        with self.assertRaises(ValueError):
            self.calculator.calculate_tip(Decimal('100.00'), Decimal('-10'), 1)

        # Test invalid number of people
        with self.assertRaises(ValueError):
            self.calculator.calculate_tip(Decimal('100.00'), Decimal('10'), 0)

    def test_currency_change(self):
        # Test currency change functionality
        self.calculator.set_currency('EUR')
        self.assertEqual(self.calculator.current_currency, 'EUR')
        
        # Test invalid currency
        with self.assertRaises(ValueError):
            self.calculator.set_currency('XXX')

    def test_history_management(self):
        # Test history recording
        self.calculator.calculate_tip(Decimal('100.00'), Decimal('10'), 1)
        history = self.calculator.get_history()
        self.assertEqual(len(history), 1)

        # Test history clearing
        self.calculator.clear_history()
        self.assertEqual(len(self.calculator.get_history()), 0)

if __name__ == '__main__':
    unittest.main()