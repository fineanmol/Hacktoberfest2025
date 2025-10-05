from decimal import Decimal, ROUND_HALF_UP
from typing import List, Dict
from datetime import datetime

class TipCalculator:
    def __init__(self):
        self.currency_symbols = {
            'INR': '₹',
            'USD': '$',
            'EUR': '€',
            'GBP': '£'
        }
        self.current_currency = 'INR'
        self.history: List[Dict] = []

    def format_amount(self, amount: Decimal) -> str:
        """Format the amount with currency symbol and proper decimal places."""
        amount = amount.quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)
        return f"{self.currency_symbols[self.current_currency]}{amount:,.2f}"

    def calculate_tip(self, bill_amount: Decimal, tip_percentage: Decimal, num_people: int = 1) -> Dict:
        """Calculate tip and split bill among people."""
        if bill_amount <= 0 or tip_percentage < 0 or num_people < 1:
            raise ValueError("Invalid input: Bill amount must be positive, tip percentage non-negative, and at least 1 person")

        tip_amount = (bill_amount * tip_percentage / Decimal('100')).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)
        total_amount = bill_amount + tip_amount
        per_person = (total_amount / Decimal(num_people)).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)

        result = {
            'bill_amount': self.format_amount(bill_amount),
            'tip_percentage': f"{tip_percentage}%",
            'tip_amount': self.format_amount(tip_amount),
            'total_amount': self.format_amount(total_amount),
            'num_people': num_people,
            'per_person': self.format_amount(per_person),
            'timestamp': datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        }

        self.history.append(result)
        return result

    def set_currency(self, currency_code: str) -> None:
        """Set the currency for formatting amounts."""
        if currency_code not in self.currency_symbols:
            raise ValueError(f"Unsupported currency. Supported currencies: {', '.join(self.currency_symbols.keys())}")
        self.current_currency = currency_code

    def get_history(self) -> List[Dict]:
        """Get calculation history."""
        return self.history

    def clear_history(self) -> None:
        """Clear calculation history."""
        self.history = []

def main():
    calculator = TipCalculator()
    
    while True:
        try:
            print("\nTip Calculator Menu:")
            print("1. Calculate Tip")
            print("2. Change Currency")
            print("3. View History")
            print("4. Clear History")
            print("5. Exit")
            
            choice = input("\nEnter your choice (1-5): ")
            
            if choice == '1':
                bill_str = input("Enter the bill amount: ")
                tip_str = input("Enter the tip percentage: ")
                num_people_str = input("Enter number of people splitting the bill (default 1): ").strip() or '1'
                
                try:
                    bill_amount = Decimal(bill_str)
                    tip_percentage = Decimal(tip_str)
                    num_people = int(num_people_str)
                    
                    result = calculator.calculate_tip(bill_amount, tip_percentage, num_people)
                    
                    print("\nCalculation Results:")
                    print(f"Bill Amount: {result['bill_amount']}")
                    print(f"Tip ({result['tip_percentage']}): {result['tip_amount']}")
                    print(f"Total Amount: {result['total_amount']}")
                    if num_people > 1:
                        print(f"Amount per person ({num_people} people): {result['per_person']}")
                
                except (ValueError, decimal.InvalidOperation) as e:
                    print(f"\nError: {str(e)}")
            
            elif choice == '2':
                print("\nAvailable currencies:")
                for code, symbol in calculator.currency_symbols.items():
                    print(f"{code} ({symbol})")
                currency = input("Enter currency code: ").upper()
                try:
                    calculator.set_currency(currency)
                    print(f"Currency changed to {currency}")
                except ValueError as e:
                    print(f"\nError: {str(e)}")
            
            elif choice == '3':
                history = calculator.get_history()
                if not history:
                    print("\nNo calculation history available.")
                else:
                    print("\nCalculation History:")
                    for i, calc in enumerate(history, 1):
                        print(f"\n{i}. {calc['timestamp']}")
                        print(f"   Bill: {calc['bill_amount']}")
                        print(f"   Tip: {calc['tip_amount']} ({calc['tip_percentage']})")
                        print(f"   Total: {calc['total_amount']}")
                        if calc['num_people'] > 1:
                            print(f"   Per Person ({calc['num_people']} people): {calc['per_person']}")
            
            elif choice == '4':
                calculator.clear_history()
                print("\nHistory cleared.")
            
            elif choice == '5':
                print("\nThank you for using the Tip Calculator!")
                break
            
            else:
                print("\nInvalid choice. Please enter a number between 1 and 5.")
                
        except Exception as e:
            print(f"\nAn unexpected error occurred: {str(e)}")

if __name__ == "__main__":
    main()



