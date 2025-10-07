"""
Binary Search Tree (BST) Implementation
========================================

A Binary Search Tree is a node-based binary tree data structure with the following properties:
- The left subtree of a node contains only nodes with keys less than the node's key
- The right subtree of a node contains only nodes with keys greater than the node's key
- Both the left and right subtrees must also be binary search trees
- No duplicate nodes

Operations:
- insert(value): Insert a new node - Average O(log n), Worst O(n)
- search(value): Search for a value - Average O(log n), Worst O(n)
- delete(value): Delete a node - Average O(log n), Worst O(n)
- inorder_traversal(): Left -> Root -> Right - O(n)
- preorder_traversal(): Root -> Left -> Right - O(n)
- postorder_traversal(): Left -> Right -> Root - O(n)

Real-world applications:
- Database indexing
- File system organization
- Expression trees
- Auto-complete features
- Decision trees in machine learning
"""


class Node:
    """A node in the Binary Search Tree."""
    
    def __init__(self, value):
        """
        Initialize a tree node.
        
        Args:
            value: The value to store in the node
        """
        self.value = value
        self.left = None
        self.right = None


class BinarySearchTree:
    """A Binary Search Tree implementation."""
    
    def __init__(self):
        """Initialize an empty BST."""
        self.root = None
    
    def insert(self, value):
        """
        Insert a new value into the BST.
        
        Args:
            value: The value to insert
        
        Time Complexity: Average O(log n), Worst O(n)
        """
        if self.root is None:
            self.root = Node(value)
            print(f"Inserted {value} as root")
        else:
            self._insert_recursive(self.root, value)
    
    def _insert_recursive(self, node, value):
        """Helper method to recursively insert a value."""
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
                print(f"Inserted {value} to the left of {node.value}")
            else:
                self._insert_recursive(node.left, value)
        elif value > node.value:
            if node.right is None:
                node.right = Node(value)
                print(f"Inserted {value} to the right of {node.value}")
            else:
                self._insert_recursive(node.right, value)
        else:
            print(f"Value {value} already exists in the tree")
    
    def search(self, value):
        """
        Search for a value in the BST.
        
        Args:
            value: The value to search for
        
        Returns:
            bool: True if value exists, False otherwise
        
        Time Complexity: Average O(log n), Worst O(n)
        """
        return self._search_recursive(self.root, value)
    
    def _search_recursive(self, node, value):
        """Helper method to recursively search for a value."""
        if node is None:
            return False
        
        if value == node.value:
            return True
        elif value < node.value:
            return self._search_recursive(node.left, value)
        else:
            return self._search_recursive(node.right, value)
    
    def inorder_traversal(self):
        """
        Perform inorder traversal (Left -> Root -> Right).
        Returns sorted order for BST.
        
        Returns:
            list: List of values in inorder
        
        Time Complexity: O(n)
        """
        result = []
        self._inorder_recursive(self.root, result)
        return result
    
    def _inorder_recursive(self, node, result):
        """Helper method for inorder traversal."""
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.value)
            self._inorder_recursive(node.right, result)
    
    def preorder_traversal(self):
        """
        Perform preorder traversal (Root -> Left -> Right).
        
        Returns:
            list: List of values in preorder
        
        Time Complexity: O(n)
        """
        result = []
        self._preorder_recursive(self.root, result)
        return result
    
    def _preorder_recursive(self, node, result):
        """Helper method for preorder traversal."""
        if node:
            result.append(node.value)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)
    
    def postorder_traversal(self):
        """
        Perform postorder traversal (Left -> Right -> Root).
        
        Returns:
            list: List of values in postorder
        
        Time Complexity: O(n)
        """
        result = []
        self._postorder_recursive(self.root, result)
        return result
    
    def _postorder_recursive(self, node, result):
        """Helper method for postorder traversal."""
        if node:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.append(node.value)
    
    def find_min(self):
        """
        Find the minimum value in the BST.
        
        Returns:
            The minimum value, or None if tree is empty
        
        Time Complexity: O(h) where h is height
        """
        if self.root is None:
            return None
        
        current = self.root
        while current.left:
            current = current.left
        return current.value
    
    def find_max(self):
        """
        Find the maximum value in the BST.
        
        Returns:
            The maximum value, or None if tree is empty
        
        Time Complexity: O(h) where h is height
        """
        if self.root is None:
            return None
        
        current = self.root
        while current.right:
            current = current.right
        return current.value
    
    def height(self):
        """
        Calculate the height of the BST.
        
        Returns:
            int: Height of the tree
        
        Time Complexity: O(n)
        """
        return self._height_recursive(self.root)
    
    def _height_recursive(self, node):
        """Helper method to calculate height."""
        if node is None:
            return -1
        
        left_height = self._height_recursive(node.left)
        right_height = self._height_recursive(node.right)
        
        return max(left_height, right_height) + 1
    
    def count_nodes(self):
        """
        Count total number of nodes in the BST.
        
        Returns:
            int: Total number of nodes
        
        Time Complexity: O(n)
        """
        return self._count_recursive(self.root)
    
    def _count_recursive(self, node):
        """Helper method to count nodes."""
        if node is None:
            return 0
        return 1 + self._count_recursive(node.left) + self._count_recursive(node.right)
    
    def display_tree(self, node=None, level=0, prefix="Root: "):
        """
        Display the tree structure visually.
        
        Args:
            node: Current node (default: root)
            level: Current level in tree
            prefix: Prefix string for display
        """
        if node is None:
            node = self.root
        
        if node is None:
            print("Tree is empty")
            return
        
        print(" " * (level * 4) + prefix + str(node.value))
        
        if node.left:
            self.display_tree(node.left, level + 1, "L--- ")
        
        if node.right:
            self.display_tree(node.right, level + 1, "R--- ")


# Example usage and demonstrations
if __name__ == "__main__":
    print("=" * 60)
    print("BINARY SEARCH TREE DEMONSTRATION")
    print("=" * 60)
    
    # Create a BST
    print("\n1. Creating BST and inserting values:")
    print("-" * 60)
    bst = BinarySearchTree()
    
    # Insert values
    values = [50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 65]
    for value in values:
        bst.insert(value)
    
    # Display tree structure
    print("\n2. Tree Structure:")
    print("-" * 60)
    bst.display_tree()
    
    # Traversals
    print("\n3. Tree Traversals:")
    print("-" * 60)
    print(f"Inorder (sorted):   {bst.inorder_traversal()}")
    print(f"Preorder:           {bst.preorder_traversal()}")
    print(f"Postorder:          {bst.postorder_traversal()}")
    
    # Search operations
    print("\n4. Search Operations:")
    print("-" * 60)
    search_values = [40, 55, 80, 100]
    for value in search_values:
        found = "✓ Found" if bst.search(value) else "✗ Not Found"
        print(f"Search for {value:3}: {found}")
    
    # Tree properties
    print("\n5. Tree Properties:")
    print("-" * 60)
    print(f"Minimum value:      {bst.find_min()}")
    print(f"Maximum value:      {bst.find_max()}")
    print(f"Tree height:        {bst.height()}")
    print(f"Total nodes:        {bst.count_nodes()}")
    
    # Practical example
    print("\n" + "=" * 60)
    print("6. Practical Example - Student Grade Management:")
    print("=" * 60)
    
    grade_tree = BinarySearchTree()
    students = [
        (85, "Alice"), (72, "Bob"), (93, "Charlie"),
        (65, "David"), (88, "Eve"), (79, "Frank")
    ]
    
    print("\nAdding student grades:")
    for grade, name in students:
        grade_tree.insert(grade)
        print(f"  {name}: {grade}")
    
    print("\nGrades in sorted order (Inorder traversal):")
    sorted_grades = grade_tree.inorder_traversal()
    print(f"  {sorted_grades}")
    
    print("\nTree visualization:")
    grade_tree.display_tree()
    
    print("\n" + "=" * 60)
