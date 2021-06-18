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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode tmp = head;
        
        while(tmp != null){
            ListNode nxt = tmp.next;
            tmp.next = prev;
            prev = tmp;
            tmp = nxt;
        }
        return prev;
    }
}