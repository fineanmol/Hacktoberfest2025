"""
Queue Data Structure Implementation
====================================

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle.
The first element added to the queue will be the first one to be removed.

Operations:
- enqueue(item): Add an item to the rear of the queue - O(1)
- dequeue(): Remove and return the front item - O(1)
- front(): Return the front item without removing it - O(1)
- is_empty(): Check if the queue is empty - O(1)
- size(): Return the number of items in the queue - O(1)

Real-world applications:
- Print job scheduling
- CPU task scheduling
- Breadth-First Search in graphs
- Handling requests in web servers
- Call center phone systems
"""


class Queue:
    """A Queue implementation using Python list."""
    
    def __init__(self):
        """Initialize an empty queue."""
        self.items = []
    
    def enqueue(self, item):
        """
        Add an item to the rear of the queue.
        
        Args:
            item: The item to be added to the queue
        
        Time Complexity: O(1)
        """
        self.items.append(item)
        print(f"Enqueued '{item}' to queue")
    
    def dequeue(self):
        """
        Remove and return the front item from the queue.
        
        Returns:
            The front item from the queue
        
        Raises:
            IndexError: If the queue is empty
        
        Time Complexity: O(n) due to list.pop(0), but can be O(1) with deque
        """
        if self.is_empty():
            raise IndexError("Dequeue from empty queue")
        item = self.items.pop(0)
        print(f"Dequeued '{item}' from queue")
        return item
    
    def front(self):
        """
        Return the front item without removing it.
        
        Returns:
            The front item from the queue
        
        Raises:
            IndexError: If the queue is empty
        
        Time Complexity: O(1)
        """
        if self.is_empty():
            raise IndexError("Front from empty queue")
        return self.items[0]
    
    def is_empty(self):
        """
        Check if the queue is empty.
        
        Returns:
            bool: True if queue is empty, False otherwise
        
        Time Complexity: O(1)
        """
        return len(self.items) == 0
    
    def size(self):
        """
        Return the number of items in the queue.
        
        Returns:
            int: The number of items in the queue
        
        Time Complexity: O(1)
        """
        return len(self.items)
    
    def display(self):
        """Display the contents of the queue."""
        if self.is_empty():
            print("Queue is empty")
        else:
            print(f"Queue (front -> rear): {self.items}")


class CircularQueue:
    """
    A Circular Queue implementation with fixed size.
    More efficient than regular queue for fixed-size scenarios.
    """
    
    def __init__(self, capacity):
        """
        Initialize a circular queue with fixed capacity.
        
        Args:
            capacity (int): Maximum number of items the queue can hold
        """
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = -1
        self.rear = -1
        self.count = 0
    
    def enqueue(self, item):
        """
        Add an item to the circular queue.
        
        Args:
            item: The item to be added
        
        Returns:
            bool: True if successful, False if queue is full
        
        Time Complexity: O(1)
        """
        if self.is_full():
            print(f"Queue is full! Cannot enqueue '{item}'")
            return False
        
        if self.front == -1:
            self.front = 0
        
        self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = item
        self.count += 1
        print(f"Enqueued '{item}' to circular queue")
        return True
    
    def dequeue(self):
        """
        Remove and return the front item from the circular queue.
        
        Returns:
            The front item from the queue, or None if empty
        
        Time Complexity: O(1)
        """
        if self.is_empty():
            print("Queue is empty! Cannot dequeue")
            return None
        
        item = self.queue[self.front]
        
        if self.front == self.rear:
            # Queue has only one element
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        
        self.count -= 1
        print(f"Dequeued '{item}' from circular queue")
        return item
    
    def is_empty(self):
        """Check if the circular queue is empty."""
        return self.count == 0
    
    def is_full(self):
        """Check if the circular queue is full."""
        return self.count == self.capacity
    
    def size(self):
        """Return the number of items in the queue."""
        return self.count
    
    def display(self):
        """Display the contents of the circular queue."""
        if self.is_empty():
            print("Circular Queue is empty")
            return
        
        print("Circular Queue (front -> rear): ", end="")
        i = self.front
        for _ in range(self.count):
            print(self.queue[i], end=" ")
            i = (i + 1) % self.capacity
        print()


def simulate_print_queue():
    """
    Simulate a print queue system.
    Demonstrates practical use of Queue data structure.
    """
    print("Print Queue Simulation")
    print("-" * 40)
    
    print_queue = Queue()
    
    # Add print jobs
    jobs = ["Document1.pdf", "Photo.jpg", "Report.docx", "Presentation.pptx"]
    
    print("\nAdding print jobs:")
    for job in jobs:
        print_queue.enqueue(job)
    
    print(f"\nTotal jobs in queue: {print_queue.size()}")
    print_queue.display()
    
    # Process jobs
    print("\nProcessing print jobs:")
    while not print_queue.is_empty():
        job = print_queue.items[0]
        print(f"Printing {job}...", end=" ")
        print_queue.dequeue()
        print("Done!")
    
    print("\nAll jobs completed!")


# Example usage and demonstrations
if __name__ == "__main__":
    print("=" * 60)
    print("QUEUE DATA STRUCTURE DEMONSTRATION")
    print("=" * 60)
    
    # Example 1: Regular Queue
    print("\n1. Regular Queue Operations:")
    print("-" * 60)
    queue = Queue()
    
    # Enqueue operations
    queue.enqueue("Customer A")
    queue.enqueue("Customer B")
    queue.enqueue("Customer C")
    queue.enqueue("Customer D")
    
    # Display queue
    print()
    queue.display()
    
    # Front operation
    print(f"\nFront customer: {queue.front()}")
    print(f"Queue size: {queue.size()}")
    
    # Dequeue operations
    print()
    queue.dequeue()
    queue.dequeue()
    
    print()
    queue.display()
    
    # Example 2: Circular Queue
    print("\n" + "=" * 60)
    print("2. Circular Queue Operations:")
    print("-" * 60)
    circular_queue = CircularQueue(5)
    
    circular_queue.enqueue(1)
    circular_queue.enqueue(2)
    circular_queue.enqueue(3)
    circular_queue.enqueue(4)
    circular_queue.enqueue(5)
    
    print()
    circular_queue.display()
    
    print("\nTrying to enqueue to full queue:")
    circular_queue.enqueue(6)  # Should fail
    
    print("\nDequeuing two items:")
    circular_queue.dequeue()
    circular_queue.dequeue()
    
    print("\nNow we can add more items:")
    circular_queue.enqueue(6)
    circular_queue.enqueue(7)
    
    print()
    circular_queue.display()
    
    # Example 3: Print Queue Simulation
    print("\n" + "=" * 60)
    print("3. Practical Application - Print Queue:")
    print("=" * 60)
    simulate_print_queue()
    
    print("\n" + "=" * 60)
