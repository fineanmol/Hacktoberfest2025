#include <iostream>

// Linked list node structure
struct Node {
  int data;
  Node * next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(Node * & head, int data) {
  Node * newNode = new Node; // Creating a new node
  newNode -> data = data; // Assigning data to the new node
  newNode -> next = head; // Setting the next pointer of the new node to the current head
  head = newNode; // Updating the head to point to the new node
}

// Function to print the linked list
void print_List(Node * head) {
  while (head != nullptr) { // Loop to traverse the linked list until the end (nullptr)
    std::cout << head -> data << " "; // Printing the data of the current node
    head = head -> next; // Moving to the next node
  }
  std::cout << std::endl; // Printing a new line after the linked list elements
}

// Recursive function to reverse the linked list
Node * reverse_List(Node * current, Node * previous = nullptr) {
  if (current == nullptr) // Base case: if the current node is nullptr (end of the list), return the previous node
    return previous;

  Node * nextNode = current -> next; // Storing the next node
  current -> next = previous; // Reversing the pointer to the previous node
  return reverse_List(nextNode, current); // Recursively call the function with updated pointers
}

int main() {
  Node * head = nullptr; // Initializing the head of the linked list to nullptr

  // Insert elements into the linked list
  insertNode(head, 5);
  insertNode(head, 4);
  insertNode(head, 3);
  insertNode(head, 2);
  insertNode(head, 1);

  std::cout << "Original Linked List: ";
  print_List(head); // Printing the original linked list

  // Reverse the linked list using recursion
  head = reverse_List(head); // Reversing the linked list

  std::cout << "Reversed Linked List: ";
  print_List(head); // Printing the reversed linked list

  return 0; // Returning 0 to indicate successful execution of the program
}
