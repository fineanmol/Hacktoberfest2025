"""
Stack Data Structure Implementation
====================================

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle.
The last element added to the stack will be the first one to be removed.

Operations:
- push(item): Add an item to the top of the stack - O(1)
- pop(): Remove and return the top item - O(1)
- peek(): Return the top item without removing it - O(1)
- is_empty(): Check if the stack is empty - O(1)
- size(): Return the number of items in the stack - O(1)

Real-world applications:
- Browser back/forward navigation
- Undo/Redo functionality in text editors
- Function call stack in programming languages
- Expression evaluation and syntax parsing
"""


class Stack:
    """A Stack implementation using Python list."""
    
    def __init__(self):
        """Initialize an empty stack."""
        self.items = []
    
    def push(self, item):
        """
        Add an item to the top of the stack.
        
        Args:
            item: The item to be added to the stack
        
        Time Complexity: O(1)
        """
        self.items.append(item)
        print(f"Pushed '{item}' to stack")
    
    def pop(self):
        """
        Remove and return the top item from the stack.
        
        Returns:
            The top item from the stack
        
        Raises:
            IndexError: If the stack is empty
        
        Time Complexity: O(1)
        """
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        item = self.items.pop()
        print(f"Popped '{item}' from stack")
        return item
    
    def peek(self):
        """
        Return the top item without removing it.
        
        Returns:
            The top item from the stack
        
        Raises:
            IndexError: If the stack is empty
        
        Time Complexity: O(1)
        """
        if self.is_empty():
            raise IndexError("Peek from empty stack")
        return self.items[-1]
    
    def is_empty(self):
        """
        Check if the stack is empty.
        
        Returns:
            bool: True if stack is empty, False otherwise
        
        Time Complexity: O(1)
        """
        return len(self.items) == 0
    
    def size(self):
        """
        Return the number of items in the stack.
        
        Returns:
            int: The number of items in the stack
        
        Time Complexity: O(1)
        """
        return len(self.items)
    
    def display(self):
        """Display the contents of the stack."""
        if self.is_empty():
            print("Stack is empty")
        else:
            print(f"Stack (top -> bottom): {self.items[::-1]}")


def reverse_string_using_stack(text):
    """
    Reverse a string using a stack.
    
    Args:
        text (str): The string to reverse
    
    Returns:
        str: The reversed string
    
    Example:
        >>> reverse_string_using_stack("Hello")
        'olleH'
    """
    stack = Stack()
    
    # Push all characters onto the stack
    for char in text:
        stack.items.append(char)  # Using internal method to avoid print
    
    # Pop all characters to get reversed string
    reversed_text = ""
    while not stack.is_empty():
        reversed_text += stack.items.pop()  # Using internal method
    
    return reversed_text


def is_balanced_parentheses(expression):
    """
    Check if parentheses in an expression are balanced.
    
    Args:
        expression (str): The expression to check
    
    Returns:
        bool: True if balanced, False otherwise
    
    Example:
        >>> is_balanced_parentheses("(()())")
        True
        >>> is_balanced_parentheses("(()")
        False
    """
    stack = Stack()
    opening = "([{"
    closing = ")]}"
    pairs = {')': '(', ']': '[', '}': '{'}
    
    for char in expression:
        if char in opening:
            stack.items.append(char)
        elif char in closing:
            if stack.is_empty() or stack.items[-1] != pairs[char]:
                return False
            stack.items.pop()
    
    return stack.is_empty()


# Example usage and demonstrations
if __name__ == "__main__":
    print("=" * 60)
    print("STACK DATA STRUCTURE DEMONSTRATION")
    print("=" * 60)
    
    # Create a new stack
    print("\n1. Creating a new stack and performing operations:")
    print("-" * 60)
    stack = Stack()
    
    # Push operations
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.push(40)
    
    # Display stack
    print()
    stack.display()
    
    # Peek operation
    print(f"\nTop element (peek): {stack.peek()}")
    print(f"Stack size: {stack.size()}")
    
    # Pop operations
    print()
    stack.pop()
    stack.pop()
    
    print()
    stack.display()
    
    # Example 2: Reverse a string
    print("\n" + "=" * 60)
    print("2. Reversing a string using stack:")
    print("-" * 60)
    original = "Hacktoberfest"
    reversed_str = reverse_string_using_stack(original)
    print(f"Original: {original}")
    print(f"Reversed: {reversed_str}")
    
    # Example 3: Check balanced parentheses
    print("\n" + "=" * 60)
    print("3. Checking balanced parentheses:")
    print("-" * 60)
    test_expressions = [
        "(()())",
        "((()))",
        "(())",
        "())",
        "(()",
        "{[()]}",
        "{[(])}",
    ]
    
    for expr in test_expressions:
        result = "✓ Balanced" if is_balanced_parentheses(expr) else "✗ Not Balanced"
        print(f"{expr:12} -> {result}")
    
    print("\n" + "=" * 60)
