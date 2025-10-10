// MergeSortLinkedList.cpp
// Implementation of Merge Sort using Linked List (Recursive Approach)
// Author: <your-name>
// Hacktoberfest 2025 Contribution

#include <iostream>
using namespace std;

// Definition of a Linked List Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to find the middle of the linked list
Node* getMiddle(Node* head) {
    if (!head) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on linked list
Node* mergeSort(Node* head) {
    // Base case: if head is null or only one element
    if (!head || !head->next)
        return head;

    // Step 1: Split the list into halves
    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;
    middle->next = nullptr;

    // Step 2: Apply mergeSort on each half
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);

    // Step 3: Merge the sorted halves
    Node* sortedList = merge(left, right);

    return sortedList;
}

// Helper function to insert node at end
void pushBack(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Driver code for testing
int main() {
    Node* head = nullptr;

    // Sample input
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pushBack(head, val);
    }

    cout << "\nOriginal List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
