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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null) return null;
        ListNode x = head;
        while(x != null && x.val == val) x = x.next;
        if(x == null) return null;
        ListNode tmp = x;
        while(x.next != null){
            if(x.next.val == val){
                x.next = x.next.next;
            }
            else{
                x = x.next;
            }
        }
        
        return tmp;
    }
}