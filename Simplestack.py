class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)
        print(f'Pushed {item} to stack.')

    def pop(self):
        if self.is_empty():
            print('Stack is empty!')
            return None
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            print('Stack is empty!')
            return None
        return self.items[-1]

    def size(self):
        return len(self.items)


# Driver code to test stack
stack = Stack()
stack.push(5)
stack.push(10)
print(f'Top element is {stack.peek()}')
print(f'Stack size is {stack.size()}')
print(f'Popped element is {stack.pop()}')
print(f'Stack is empty: {stack.is_empty()}')
