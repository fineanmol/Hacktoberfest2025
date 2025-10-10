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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        boolean carry = false;
        ListNode res=null;
        ListNode temp = null;

        while(l1!=null || l2!=null || carry){
            int sum = 0;

            if(l1!=null){
                sum+=l1.val;
                l1 = l1.next;
            }
            if(l2!=null){
                sum+=l2.val;
                l2 = l2.next;
            }

            if(carry){
                sum++;
                carry = false;
            }  
            if(sum>9){
                carry = true;
                sum = sum%10;
            }

            ListNode newNode = new ListNode(sum);
            if(temp==null){
                temp = newNode;
                res = newNode;
            }
            else{
                temp.next = newNode;
                temp = newNode;
            }
        }

        return res;
    }
}
