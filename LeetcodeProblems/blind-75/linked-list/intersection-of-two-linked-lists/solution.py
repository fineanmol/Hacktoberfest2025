# Intersection of Two Linked Lists - LeetCode #160

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a = headA
        b = headB
        
        while a != b:
            a = headB if not a else a.next
            b = headA if not b else b.next
        
        return a
