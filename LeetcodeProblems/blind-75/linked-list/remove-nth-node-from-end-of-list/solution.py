# Remove Nth Node From End of List - LeetCode #19

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fast = dummy
        slow = dummy
        
        # Move fast n+1 steps
        for _ in range(n + 1):
            fast = fast.next
        
        # Move both
        while fast:
            fast = fast.next
            slow = slow.next
        
        # Remove
        slow.next = slow.next.next
        
        return dummy.next
