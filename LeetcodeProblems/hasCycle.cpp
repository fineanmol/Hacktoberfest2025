/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // fast pointer and slow pointer 
        // fast pointer node -> next -> next 
        // slow poointer node -> next
        if(head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast != nullptr && fast->next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
