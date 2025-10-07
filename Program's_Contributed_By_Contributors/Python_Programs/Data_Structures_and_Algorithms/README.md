# 📚 Data Structures and Algorithms in Python

A comprehensive collection of fundamental data structures and algorithms implemented in Python with detailed documentation, examples, and real-world applications.

## 📋 Table of Contents

- [Overview](#overview)
- [Implemented Data Structures](#implemented-data-structures)
- [Features](#features)
- [How to Use](#how-to-use)
- [Time Complexity Summary](#time-complexity-summary)
- [Prerequisites](#prerequisites)
- [Contributing](#contributing)

---

## 🎯 Overview

This collection provides clean, well-documented implementations of essential data structures and algorithms. Each implementation includes:

- ✅ **Detailed documentation** with docstrings
- ✅ **Time complexity analysis** for all operations
- ✅ **Real-world applications** and use cases
- ✅ **Practical examples** demonstrating usage
- ✅ **Test demonstrations** that can be run directly

Perfect for:
- 🎓 Learning data structures and algorithms
- 📝 Interview preparation
- 🔍 Reference implementations
- 🚀 Understanding practical applications

---

## 📊 Implemented Data Structures

### 1. **Stack** (`stack.py`)

A Last-In-First-Out (LIFO) data structure.

**Operations:**
- `push(item)` - Add item to top - **O(1)**
- `pop()` - Remove and return top item - **O(1)**
- `peek()` - View top item without removing - **O(1)**
- `is_empty()` - Check if stack is empty - **O(1)**
- `size()` - Get number of items - **O(1)**

**Real-world applications:**
- Browser back/forward navigation
- Undo/Redo functionality in text editors
- Function call stack in programming languages
- Expression evaluation and syntax parsing
- Backtracking algorithms

**Included Examples:**
- ✓ String reversal using stack
- ✓ Balanced parentheses checker
- ✓ Basic stack operations demonstration

**Run it:**
```bash
python stack.py
```

---

### 2. **Queue** (`queue.py`)

A First-In-First-Out (FIFO) data structure with both regular and circular implementations.

**Operations:**
- `enqueue(item)` - Add item to rear - **O(1)**
- `dequeue()` - Remove and return front item - **O(n) for list, O(1) for deque**
- `front()` - View front item without removing - **O(1)**
- `is_empty()` - Check if queue is empty - **O(1)**
- `size()` - Get number of items - **O(1)**

**Real-world applications:**
- Print job scheduling
- CPU task scheduling
- Breadth-First Search in graphs
- Handling requests in web servers
- Call center phone systems

**Included Examples:**
- ✓ Regular queue operations
- ✓ Circular queue implementation (more efficient)
- ✓ Print queue simulation

**Run it:**
```bash
python queue.py
```

---

### 3. **Binary Search Tree (BST)** (`binary_search_tree.py`)

A node-based tree structure where left children are smaller and right children are larger than their parent.

**Operations:**
- `insert(value)` - Insert new node - **Average O(log n), Worst O(n)**
- `search(value)` - Search for value - **Average O(log n), Worst O(n)**
- `delete(value)` - Delete node - **Average O(log n), Worst O(n)**
- `inorder_traversal()` - Get sorted order - **O(n)**
- `preorder_traversal()` - Root-first traversal - **O(n)**
- `postorder_traversal()` - Root-last traversal - **O(n)**
- `find_min()` - Find minimum value - **O(h)**
- `find_max()` - Find maximum value - **O(h)**
- `height()` - Calculate tree height - **O(n)**

**Real-world applications:**
- Database indexing
- File system organization
- Expression trees
- Auto-complete features
- Decision trees in machine learning

**Included Examples:**
- ✓ Building a BST with insertions
- ✓ All traversal methods (inorder, preorder, postorder)
- ✓ Search operations
- ✓ Finding min/max values
- ✓ Tree visualization
- ✓ Student grade management system

**Run it:**
```bash
python binary_search_tree.py
```

---

## ✨ Features

### 🎨 Clean, Readable Code
All implementations follow Python best practices:
- Clear variable names
- Comprehensive docstrings
- Type hints where applicable
- Proper error handling

### 📖 Educational Documentation
Every file includes:
- Algorithm explanation
- Time/space complexity analysis
- Real-world use cases
- Step-by-step examples

### 🧪 Runnable Demonstrations
Each file can be executed directly to see demonstrations:
```bash
python stack.py           # See stack in action
python queue.py           # See queue examples
python binary_search_tree.py  # See BST operations
```

### 💡 Practical Applications
Every implementation includes realistic examples showing how these structures are used in real software.

---

## 🚀 How to Use

### Option 1: Run Demonstrations
Simply execute any file to see examples:
```bash
cd Program's_Contributed_By_Contributors/Python_Programs/Data_Structures_and_Algorithms
python stack.py
```

### Option 2: Import in Your Code
Use the classes in your own projects:

```python
from stack import Stack

# Create and use a stack
my_stack = Stack()
my_stack.push(10)
my_stack.push(20)
print(my_stack.pop())  # Output: 20
```

```python
from queue import Queue

# Create and use a queue
my_queue = Queue()
my_queue.enqueue("First")
my_queue.enqueue("Second")
print(my_queue.dequeue())  # Output: First
```

```python
from binary_search_tree import BinarySearchTree

# Create and use a BST
bst = BinarySearchTree()
bst.insert(50)
bst.insert(30)
bst.insert(70)
print(bst.inorder_traversal())  # Output: [30, 50, 70]
```

### Option 3: Study the Code
Read through the implementations to understand:
- How each data structure works internally
- Time complexity of operations
- Best practices in Python

---

## ⏱️ Time Complexity Summary

| Data Structure | Insert | Delete | Search | Access | Space |
|---------------|--------|--------|--------|--------|-------|
| **Stack** | O(1) | O(1) | O(n) | O(n) | O(n) |
| **Queue** | O(1) | O(n)* | O(n) | O(n) | O(n) |
| **BST (avg)** | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| **BST (worst)** | O(n) | O(n) | O(n) | O(n) | O(n) |

\* O(1) with `collections.deque`

---

## 📚 Prerequisites

- **Python 3.6+** (recommended Python 3.8+)
- No external dependencies required! Pure Python implementations.

---

## 🎓 Learning Path

Recommended order for beginners:

1. **Start with Stack** (`stack.py`)
   - Simplest data structure
   - Easy to visualize
   - Learn LIFO principle

2. **Move to Queue** (`queue.py`)
   - Similar to Stack but FIFO
   - Understand circular queues
   - See practical applications

3. **Advanced: Binary Search Tree** (`binary_search_tree.py`)
   - Understand tree structures
   - Learn recursion
   - Master tree traversals

---

## 🤝 Contributing

Found a bug? Want to add a feature? Contributions are welcome!

**Ideas for contributions:**
- Add more algorithms (sorting, searching)
- Implement additional data structures (Linked Lists, Hash Tables, Heaps)
- Add unit tests
- Improve documentation
- Add visualizations
- Optimize existing implementations

---

## 📝 Code Quality

All implementations feature:
- ✅ **PEP 8 compliant** - Follows Python style guidelines
- ✅ **Well-documented** - Every method has docstrings
- ✅ **Error handling** - Proper exception handling
- ✅ **Self-contained** - No external dependencies
- ✅ **Educational** - Written to teach, not just to work

---

## 🌟 Highlights

### What Makes This Collection Special?

1. **Beginner-Friendly**: Clear explanations and simple code
2. **Production-Ready**: Proper error handling and edge cases
3. **Well-Tested**: Includes demonstrations proving correctness
4. **Practical**: Shows real-world applications
5. **Complete**: Not just code - includes documentation and examples

---

## 📖 Additional Resources

Want to learn more? Check these out:

- [Python Official Documentation](https://docs.python.org/3/)
- [Big O Notation Guide](https://www.bigocheatsheet.com/)
- [Data Structures Visualization](https://visualgo.net/)
- [Python Data Structures Tutorial](https://realpython.com/python-data-structures/)

---

## 🎉 About This Contribution

This collection was created as part of **Hacktoberfest 2025** to provide high-quality, educational resources for the open-source community. 

**Author**: @devvratpathak  
**Date**: October 2025  
**License**: Open Source (follows repository license)

---

## 📞 Feedback

Found these helpful? Have suggestions? Feel free to:
- ⭐ Star the repository
- 🐛 Report issues
- 💡 Suggest improvements
- 🤝 Contribute your own implementations

---

**Happy Learning! 🚀📚**

*Remember: Understanding data structures is key to becoming a better programmer. Take your time, run the examples, and experiment with the code!*
