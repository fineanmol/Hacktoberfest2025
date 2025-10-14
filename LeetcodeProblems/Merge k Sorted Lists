/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (ListNode listNode : lists) {
            while (listNode != null) {
                min = Math.min(listNode.val, min);
                max = Math.max(listNode.val, max);
                listNode = listNode.next;
            }
        }
        int len = max - min;

        ListNode[] tmpArray = new ListNode[len + 1];

        for (ListNode listNode : lists) {
            if (listNode != null) {
                do {
                    ListNode nex = listNode.next;
                    ListNode tem = tmpArray[listNode.val - min];
                    tmpArray[listNode.val - min] = listNode;
                    listNode.next = tem;
                    listNode = nex;
                } while (listNode != null);
            }
        }

        ListNode rs = new ListNode();
        ListNode temp = rs;

        for (ListNode listNode : tmpArray) {
            if (listNode != null) {
                temp.next = listNode;

                while (listNode.next != null) {
                    listNode = listNode.next;
                }

                temp = listNode;
            }
        }
        return rs.next;
    }
}
