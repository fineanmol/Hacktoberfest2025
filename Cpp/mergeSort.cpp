#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to split the linked list into two halves
void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

// Function to merge two sorted linked lists
Node* sortedMerge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

// Merge Sort for linked list
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return; // Base case: 0 or 1 node

    Node* a;
    Node* b;

    // Split the list into 'a' and 'b' halves
    splitList(head, &a, &b);

    // Recursively sort both halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves
    *headRef = sortedMerge(a, b);
}

// Driver code
int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    mergeSort(&head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
