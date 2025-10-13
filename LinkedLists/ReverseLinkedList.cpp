/*
 * Problem: Reverse Linked List
 * 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * Example:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) for iterative, O(n) for recursive
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative approach
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;    // Store next node
            current->next = prev;    // Reverse the link
            prev = current;          // Move prev forward
            current = next;          // Move current forward
        }
        
        return prev; // prev is now the new head
    }
    
    // Recursive approach
    ListNode* reverseListRecursive(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        ListNode* reversedHead = reverseListRecursive(head->next);
        
        // Reverse the current connection
        head->next->next = head;
        head->next = nullptr;
        
        return reversedHead;
    }
    
    // Helper function to create linked list from vector
    ListNode* createList(vector<int>& values) {
        if (values.empty()) return nullptr;
        
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        
        for (int i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        
        return head;
    }
    
    // Helper function to print linked list
    void printList(ListNode* head) {
        cout << "[";
        bool first = true;
        while (head != nullptr) {
            if (!first) cout << " -> ";
            cout << head->val;
            head = head->next;
            first = false;
        }
        cout << "]" << endl;
    }
    
    // Helper function to free memory
    void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = solution.createList(values1);
    cout << "Original List 1: ";
    solution.printList(head1);
    
    ListNode* reversed1 = solution.reverseList(head1);
    cout << "Reversed List 1: ";
    solution.printList(reversed1);
    cout << endl;
    
    // Test case 2 (Recursive approach)
    vector<int> values2 = {1, 2};
    ListNode* head2 = solution.createList(values2);
    cout << "Original List 2: ";
    solution.printList(head2);
    
    ListNode* reversed2 = solution.reverseListRecursive(head2);
    cout << "Reversed List 2 (Recursive): ";
    solution.printList(reversed2);
    cout << endl;
    
    // Test case 3 (Empty list)
    ListNode* head3 = nullptr;
    cout << "Original List 3: ";
    solution.printList(head3);
    
    ListNode* reversed3 = solution.reverseList(head3);
    cout << "Reversed List 3: ";
    solution.printList(reversed3);
    cout << endl;
    
    // Test case 4 (Single node)
    vector<int> values4 = {1};
    ListNode* head4 = solution.createList(values4);
    cout << "Original List 4: ";
    solution.printList(head4);
    
    ListNode* reversed4 = solution.reverseList(head4);
    cout << "Reversed List 4: ";
    solution.printList(reversed4);
    
    // Clean up memory
    solution.deleteList(reversed1);
    solution.deleteList(reversed2);
    solution.deleteList(reversed3);
    solution.deleteList(reversed4);
    
    return 0;
}