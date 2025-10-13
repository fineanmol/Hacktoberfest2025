/*
 * Problem: Linked List Cycle
 * 
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be 
 * reached again by continuously following the next pointer.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) for Floyd's algorithm, O(n) for hash set approach
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;      // Tortoise (moves 1 step)
        ListNode* fast = head;      // Hare (moves 2 steps)
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow pointer by 1
            fast = fast->next->next;    // Move fast pointer by 2
            
            if (slow == fast) {         // Cycle detected
                return true;
            }
        }
        
        return false; // No cycle found
    }
    
    // Alternative approach using Hash Set
    bool hasCycleHashSet(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        ListNode* current = head;
        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return true; // Cycle detected
            }
            visited.insert(current);
            current = current->next;
        }
        
        return false; // No cycle found
    }
    
    // Find the start of the cycle (if exists)
    ListNode* detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        // Step 1: Detect if cycle exists using Floyd's algorithm
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycleFound = false;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                hasCycleFound = true;
                break;
            }
        }
        
        if (!hasCycleFound) {
            return nullptr; // No cycle
        }
        
        // Step 2: Find the start of the cycle
        // Move one pointer to head, keep other at meeting point
        // Move both pointers one step at a time until they meet
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow; // Meeting point from step 1
        
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1; // Start of the cycle
    }
    
    // Helper function to create a linked list with cycle
    ListNode* createListWithCycle(vector<int>& values, int pos) {
        if (values.empty()) return nullptr;
        
        vector<ListNode*> nodes;
        
        // Create all nodes
        for (int val : values) {
            nodes.push_back(new ListNode(val));
        }
        
        // Connect nodes
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        
        // Create cycle if pos is valid
        if (pos >= 0 && pos < nodes.size()) {
            nodes[nodes.size() - 1]->next = nodes[pos];
        }
        
        return nodes[0];
    }
    
    // Helper function to create a regular linked list
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
    
    // Helper function to print linked list (only first few nodes to avoid infinite loop)
    void printList(ListNode* head, int maxNodes = 10) {
        cout << "[";
        ListNode* current = head;
        int count = 0;
        
        while (current != nullptr && count < maxNodes) {
            if (count > 0) cout << " -> ";
            cout << current->val;
            current = current->next;
            count++;
        }
        
        if (current != nullptr) {
            cout << " -> ...";
        }
        cout << "]" << endl;
    }
    
    // Helper function to delete list without cycle
    void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Helper function to delete list with potential cycle
    void deleteListWithCycle(ListNode* head) {
        if (head == nullptr) return;
        
        unordered_set<ListNode*> visited;
        while (head != nullptr && visited.find(head) == visited.end()) {
            visited.insert(head);
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1: List with cycle
    vector<int> values1 = {3, 2, 0, -4};
    ListNode* head1 = solution.createListWithCycle(values1, 1); // Cycle at position 1
    cout << "Test Case 1: List with cycle at position 1" << endl;
    cout << "List: ";
    solution.printList(head1, 8);
    cout << "Has Cycle (Floyd's): " << (solution.hasCycle(head1) ? "true" : "false") << endl;
    cout << "Has Cycle (Hash Set): " << (solution.hasCycleHashSet(head1) ? "true" : "false") << endl;
    
    ListNode* cycleStart1 = solution.detectCycle(head1);
    if (cycleStart1) {
        cout << "Cycle starts at node with value: " << cycleStart1->val << endl;
    }
    cout << endl;
    
    // Test case 2: List without cycle
    vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = solution.createList(values2);
    cout << "Test Case 2: List without cycle" << endl;
    cout << "List: ";
    solution.printList(head2);
    cout << "Has Cycle (Floyd's): " << (solution.hasCycle(head2) ? "true" : "false") << endl;
    cout << "Has Cycle (Hash Set): " << (solution.hasCycleHashSet(head2) ? "true" : "false") << endl;
    
    ListNode* cycleStart2 = solution.detectCycle(head2);
    if (cycleStart2) {
        cout << "Cycle starts at node with value: " << cycleStart2->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
    cout << endl;
    
    // Test case 3: Single node with self cycle
    vector<int> values3 = {1};
    ListNode* head3 = solution.createListWithCycle(values3, 0); // Self cycle
    cout << "Test Case 3: Single node with self cycle" << endl;
    cout << "Has Cycle (Floyd's): " << (solution.hasCycle(head3) ? "true" : "false") << endl;
    
    ListNode* cycleStart3 = solution.detectCycle(head3);
    if (cycleStart3) {
        cout << "Cycle starts at node with value: " << cycleStart3->val << endl;
    }
    cout << endl;
    
    // Test case 4: Empty list
    ListNode* head4 = nullptr;
    cout << "Test Case 4: Empty list" << endl;
    cout << "Has Cycle (Floyd's): " << (solution.hasCycle(head4) ? "true" : "false") << endl;
    
    // Clean up memory
    solution.deleteListWithCycle(head1);
    solution.deleteList(head2);
    solution.deleteListWithCycle(head3);
    
    return 0;
}