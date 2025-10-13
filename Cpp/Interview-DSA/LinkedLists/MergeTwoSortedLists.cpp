/*
 * Problem: Merge Two Sorted Lists
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by 
 * splicing together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
 * 
 * Example:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * Time Complexity: O(n + m)
 * Space Complexity: O(1) for iterative, O(n + m) for recursive
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the logic
        ListNode dummy;
        ListNode* current = &dummy;
        
        // Compare and merge nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Append remaining nodes
        current->next = (list1 != nullptr) ? list1 : list2;
        
        return dummy.next;
    }
    
    // Recursive approach
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        // Base cases
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        // Recursive merge
        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
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
    
    // Helper function to get list length
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
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
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};
    ListNode* list1 = solution.createList(values1);
    ListNode* list2 = solution.createList(values2);
    
    cout << "Test Case 1:" << endl;
    cout << "List 1: ";
    solution.printList(list1);
    cout << "List 2: ";
    solution.printList(list2);
    
    ListNode* merged1 = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    solution.printList(merged1);
    cout << endl;
    
    // Test case 2 (One empty list)
    vector<int> values3 = {};
    vector<int> values4 = {0};
    ListNode* list3 = solution.createList(values3);
    ListNode* list4 = solution.createList(values4);
    
    cout << "Test Case 2:" << endl;
    cout << "List 1: ";
    solution.printList(list3);
    cout << "List 2: ";
    solution.printList(list4);
    
    ListNode* merged2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged: ";
    solution.printList(merged2);
    cout << endl;
    
    // Test case 3 (Both empty lists)
    vector<int> values5 = {};
    vector<int> values6 = {};
    ListNode* list5 = solution.createList(values5);
    ListNode* list6 = solution.createList(values6);
    
    cout << "Test Case 3:" << endl;
    cout << "List 1: ";
    solution.printList(list5);
    cout << "List 2: ";
    solution.printList(list6);
    
    ListNode* merged3 = solution.mergeTwoLists(list5, list6);
    cout << "Merged: ";
    solution.printList(merged3);
    cout << endl;
    
    // Test case 4 (Recursive approach)
    vector<int> values7 = {1, 3, 5};
    vector<int> values8 = {2, 4, 6};
    ListNode* list7 = solution.createList(values7);
    ListNode* list8 = solution.createList(values8);
    
    cout << "Test Case 4 (Recursive):" << endl;
    cout << "List 1: ";
    solution.printList(list7);
    cout << "List 2: ";
    solution.printList(list8);
    
    ListNode* merged4 = solution.mergeTwoListsRecursive(list7, list8);
    cout << "Merged (Recursive): ";
    solution.printList(merged4);
    
    // Clean up memory
    solution.deleteList(merged1);
    solution.deleteList(merged2);
    solution.deleteList(merged3);
    solution.deleteList(merged4);
    
    return 0;
}