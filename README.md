# 🚀 Top Interview DSA Questions & Solutions in C++

[![Hacktoberfest](https://img.shields.io/badge/Hacktoberfest-2024-blueviolet.svg)](https://hacktoberfest.com/)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A comprehensive collection of **20 most frequently asked Data Structures and Algorithms interview questions** with optimized C++ solutions, multiple approaches, and detailed explanations.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [Problem Categories](#problem-categories)
- [Getting Started](#getting-started)
- [How to Run](#how-to-run)
- [Problem List](#problem-list)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This repository contains carefully selected interview questions that are:
- **Frequently Asked**: Problems commonly seen in FAANG and top tech company interviews
- **Well-Documented**: Each solution includes problem statement, examples, and complexity analysis
- **Multiple Approaches**: Different algorithmic approaches with trade-offs explained
- **Production Ready**: Clean, well-commented, and testable code

## ✨ Features

- 📚 **20 Core Problems** covering essential DSA topics
- 🔄 **Multiple Solutions** for each problem with different approaches
- ⏱️ **Time & Space Complexity** analysis for every solution
- 🧪 **Comprehensive Test Cases** with edge cases covered
- 📖 **Detailed Comments** explaining the logic and approach
- 🚀 **Optimized Code** following best practices and patterns
- 🎓 **Educational Content** with step-by-step explanations

## 📁 Repository Structure

```
Interview-DSA-CPP/
├── Arrays/                    # Array-based problems (5 problems)
│   ├── TwoSum.cpp
│   ├── MaximumSubarray.cpp
│   ├── BestTimeToBuyStock.cpp
│   ├── ContainsDuplicate.cpp
│   └── ProductExceptSelf.cpp
├── LinkedLists/              # Linked List problems (3 problems)
│   ├── ReverseLinkedList.cpp
│   ├── MergeTwoSortedLists.cpp
│   └── LinkedListCycle.cpp
├── Trees/                    # Binary Tree problems (4 problems)
│   ├── BinaryTreeInorderTraversal.cpp
│   ├── MaximumDepthBinaryTree.cpp
│   ├── ValidBST.cpp
│   └── LowestCommonAncestor.cpp
├── DynamicProgramming/       # DP problems (3 problems)
│   ├── FibonacciNumber.cpp
│   ├── ClimbingStairs.cpp
│   └── LongestCommonSubsequence.cpp
├── Strings/                  # String manipulation (3 problems)
│   ├── ValidPalindrome.cpp
│   ├── ValidAnagram.cpp
│   └── LongestSubstringWithoutRepeating.cpp
├── Graphs/                   # Graph algorithms (2 problems)
│   ├── GraphTraversal.cpp
│   └── NumberOfIslands.cpp
└── README.md
```

## 🏷️ Problem Categories

### Arrays (5 Problems)
- **Two Sum**: Hash map approach for finding pair with target sum
- **Maximum Subarray**: Kadane's algorithm for contiguous subarray
- **Best Time to Buy Stock**: Optimal buying/selling strategy
- **Contains Duplicate**: Efficient duplicate detection methods
- **Product of Array Except Self**: Calculate products without division

### Linked Lists (3 Problems)
- **Reverse Linked List**: Iterative and recursive reversal
- **Merge Two Sorted Lists**: Merging sorted sequences
- **Linked List Cycle**: Floyd's cycle detection algorithm

### Trees (4 Problems)
- **Binary Tree Traversal**: Inorder, preorder, postorder methods
- **Maximum Depth**: Tree height calculation with DFS/BFS
- **Valid Binary Search Tree**: BST validation techniques
- **Lowest Common Ancestor**: Finding LCA in binary trees

### Dynamic Programming (3 Problems)
- **Fibonacci Number**: Multiple DP approaches and optimizations
- **Climbing Stairs**: Classic step-counting problem
- **Longest Common Subsequence**: String matching with DP

### Strings (3 Problems)
- **Valid Palindrome**: Palindrome validation with preprocessing
- **Valid Anagram**: Anagram detection with frequency counting
- **Longest Substring Without Repeating**: Sliding window technique

### Graphs (2 Problems)
- **Graph Traversal**: DFS and BFS implementations
- **Number of Islands**: Connected components in 2D grid

## 🚀 Getting Started

### Prerequisites

- C++ compiler supporting C++14 or later (GCC, Clang, MSVC)
- Basic understanding of data structures and algorithms
- Familiarity with C++ STL

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/Interview-DSA-CPP.git
cd Interview-DSA-CPP
```

2. **Navigate to desired problem category**
```bash
cd Arrays  # or LinkedLists, Trees, etc.
```

3. **Compile and run**
```bash
g++ -std=c++17 -o solution TwoSum.cpp
./solution
```

## 🎮 How to Run

### Single Problem
```bash
# Compile with optimizations
g++ -std=c++17 -O2 -o two_sum Arrays/TwoSum.cpp

# Run the solution
./two_sum
```

### All Problems in Category
```bash
# Navigate to category
cd Arrays

# Compile all problems
for file in *.cpp; do
    g++ -std=c++17 -O2 -o "${file%.cpp}" "$file"
done

# Run specific solution
./TwoSum
```

### With Debugging
```bash
g++ -std=c++17 -g -DDEBUG -o debug_solution Arrays/TwoSum.cpp
gdb ./debug_solution
```

## 📝 Problem List

| # | Problem | Difficulty | Time | Space | Topics |
|---|---------|------------|------|-------|--------|
| 1 | [Two Sum](Arrays/TwoSum.cpp) | Easy | O(n) | O(n) | Array, Hash Table |
| 2 | [Maximum Subarray](Arrays/MaximumSubarray.cpp) | Medium | O(n) | O(1) | Array, DP |
| 3 | [Best Time to Buy Stock](Arrays/BestTimeToBuyStock.cpp) | Easy | O(n) | O(1) | Array, DP |
| 4 | [Contains Duplicate](Arrays/ContainsDuplicate.cpp) | Easy | O(n) | O(n) | Array, Hash Table |
| 5 | [Product Except Self](Arrays/ProductExceptSelf.cpp) | Medium | O(n) | O(1) | Array, Prefix Sum |
| 6 | [Reverse Linked List](LinkedLists/ReverseLinkedList.cpp) | Easy | O(n) | O(1) | Linked List, Recursion |
| 7 | [Merge Two Sorted Lists](LinkedLists/MergeTwoSortedLists.cpp) | Easy | O(n+m) | O(1) | Linked List, Merge |
| 8 | [Linked List Cycle](LinkedLists/LinkedListCycle.cpp) | Easy | O(n) | O(1) | Linked List, Two Pointers |
| 9 | [Binary Tree Traversal](Trees/BinaryTreeInorderTraversal.cpp) | Easy | O(n) | O(h) | Tree, DFS, Stack |
| 10 | [Maximum Depth](Trees/MaximumDepthBinaryTree.cpp) | Easy | O(n) | O(h) | Tree, DFS, BFS |
| 11 | [Valid BST](Trees/ValidBST.cpp) | Medium | O(n) | O(h) | Tree, DFS, BST |
| 12 | [Lowest Common Ancestor](Trees/LowestCommonAncestor.cpp) | Medium | O(n) | O(h) | Tree, DFS |
| 13 | [Fibonacci Number](DynamicProgramming/FibonacciNumber.cpp) | Easy | O(n) | O(1) | DP, Math |
| 14 | [Climbing Stairs](DynamicProgramming/ClimbingStairs.cpp) | Easy | O(n) | O(1) | DP |
| 15 | [Longest Common Subsequence](DynamicProgramming/LongestCommonSubsequence.cpp) | Medium | O(m×n) | O(m×n) | DP, String |
| 16 | [Valid Palindrome](Strings/ValidPalindrome.cpp) | Easy | O(n) | O(1) | String, Two Pointers |
| 17 | [Valid Anagram](Strings/ValidAnagram.cpp) | Easy | O(n) | O(1) | String, Hash Table |
| 18 | [Longest Substring Without Repeating](Strings/LongestSubstringWithoutRepeating.cpp) | Medium | O(n) | O(min(m,n)) | String, Sliding Window |
| 19 | [Graph Traversal](Graphs/GraphTraversal.cpp) | Medium | O(V+E) | O(V) | Graph, DFS, BFS |
| 20 | [Number of Islands](Graphs/NumberOfIslands.cpp) | Medium | O(m×n) | O(m×n) | Graph, DFS, BFS |

## 🔧 Code Structure

Each solution file follows this consistent structure:

```cpp
/*
 * Problem: [Problem Name]
 * 
 * [Problem Description]
 * 
 * Example:
 * Input: [example input]
 * Output: [example output]
 * 
 * Time Complexity: O(...)
 * Space Complexity: O(...)
 */

#include <iostream>
#include <vector>
// ... other includes

class Solution {
public:
    // Primary solution
    ReturnType solutionMethod(parameters) {
        // Implementation
    }
    
    // Alternative approaches
    ReturnType alternativeMethod(parameters) {
        // Different approach
    }
    
    // Helper methods
private:
    void helperMethod() {
        // Helper implementation
    }
};

int main() {
    Solution solution;
    
    // Test cases
    // Edge cases
    // Performance tests
    
    return 0;
}
```

## 💡 Key Learning Points

### Arrays
- **Hash Table Techniques**: Using unordered_map for O(1) lookups
- **Two Pointers**: Efficient array traversal patterns
- **Sliding Window**: For substring/subarray problems
- **Prefix/Suffix Arrays**: For product and sum calculations

### Linked Lists
- **Pointer Manipulation**: Safe node traversal and modification
- **Two Pointers**: Fast/slow pointer technique (Floyd's algorithm)
- **Dummy Nodes**: Simplifying edge case handling

### Trees
- **Tree Traversal**: Recursive and iterative approaches
- **Level Order**: BFS using queues
- **BST Properties**: Utilizing ordering for efficient operations
- **Tree DP**: Bottom-up and top-down approaches

### Dynamic Programming
- **Memoization**: Top-down approach with caching
- **Tabulation**: Bottom-up approach with arrays
- **Space Optimization**: Reducing space complexity
- **State Transition**: Defining recurrence relations

### Strings
- **Character Frequency**: Using arrays vs hash maps
- **String Preprocessing**: Cleaning and normalization
- **Pattern Matching**: KMP and other algorithms
- **Sliding Window**: For substring problems

### Graphs
- **Representation**: Adjacency list vs matrix
- **Traversal**: DFS and BFS implementations
- **Connected Components**: Finding separate components
- **Cycle Detection**: In directed and undirected graphs

## 🛠️ Advanced Features

### Multiple Approaches
Each problem includes:
- **Brute Force**: For understanding the problem
- **Optimized**: Best time/space complexity solution
- **Alternative**: Different algorithmic approaches
- **Extensions**: Related problem variations

### Performance Analysis
- **Time Complexity**: Big O analysis for each approach
- **Space Complexity**: Memory usage breakdown
- **Trade-offs**: When to use each approach
- **Benchmarking**: Performance comparison code

### Test Coverage
- **Happy Path**: Standard test cases
- **Edge Cases**: Empty inputs, single elements
- **Boundary Conditions**: Min/max values
- **Stress Tests**: Large input validation

## 🤝 Contributing

We welcome contributions! Here's how you can help:

### Adding New Problems
1. **Choose a problem** commonly asked in interviews
2. **Follow the template** structure for consistency
3. **Include multiple approaches** when possible
4. **Add comprehensive tests** covering edge cases
5. **Document complexity** analysis

### Improving Existing Solutions
1. **Optimize algorithms** for better performance
2. **Add alternative approaches** with different trade-offs
3. **Improve documentation** and comments
4. **Add more test cases** especially edge cases

### Code Quality Guidelines
- **Clean Code**: Readable, well-structured solutions
- **Comments**: Explain complex logic and algorithms
- **Naming**: Use descriptive variable and function names
- **Formatting**: Consistent indentation and spacing
- **Testing**: Include comprehensive test cases

### Pull Request Process
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-problem`)
3. Commit changes (`git commit -m 'Add: Two Pointers technique for Array problem'`)
4. Push to branch (`git push origin feature/new-problem`)
5. Create a Pull Request

## 📚 Additional Resources

### Learning Materials
- **Books**: "Cracking the Coding Interview", "Elements of Programming Interviews"
- **Online Judges**: LeetCode, HackerRank, CodeForces
- **Visualization**: Algorithm visualizer tools
- **Practice**: Daily coding challenges

### Interview Preparation
- **System Design**: Learn scalability concepts
- **Behavioral Questions**: Prepare STAR format answers
- **Mock Interviews**: Practice with peers or online platforms
- **Company Research**: Study specific company interview formats

### C++ Specific Resources
- **STL Reference**: Learn standard library containers and algorithms
- **Modern C++**: Features from C++11/14/17/20
- **Memory Management**: Smart pointers and RAII
- **Performance**: Optimization techniques and profiling

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Contributors**: Everyone who has contributed to this repository
- **Community**: C++ and algorithms community for inspiration
- **Companies**: Tech companies for sharing interview experiences
- **Open Source**: Libraries and tools that made this possible

## 📞 Support

If you have questions or need help:
- **Issues**: Create a GitHub issue for bugs or questions
- **Discussions**: Use GitHub Discussions for general questions
- **Email**: Contact maintainers for specific queries

## 🎯 What's Next?

### Upcoming Features
- **Video Explanations**: Walkthrough videos for complex problems
- **Interactive Tutorials**: Step-by-step problem solving
- **More Categories**: Backtracking, Divide & Conquer, etc.
- **Practice Tests**: Timed interview simulations

### Advanced Topics
- **System Design**: Scalable system architecture
- **Concurrency**: Multi-threading problems
- **Bit Manipulation**: Bitwise operation problems
- **Mathematical**: Number theory and geometry

---

⭐ **Star this repository** if you found it helpful!

🍴 **Fork it** to create your own version!

👥 **Share it** with friends preparing for interviews!

---

**Happy Coding! 🚀**