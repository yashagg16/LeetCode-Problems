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
    public ListNode middleNode(ListNode head) {
        int len = 0;
        ListNode tmp = head;
        
        while(tmp != null){
            tmp = tmp.next;
            len++;
        }
        
        int mid;
        if(len%2==0){
            mid = (len/2);
        }
        else{
            mid = (len/2);
        }
        int val = 0;
        ListNode x = null;
        tmp = head;
        while(val <= mid){
            x = tmp;
            tmp = tmp.next;
            val++;
        }
        return x;
    }
}