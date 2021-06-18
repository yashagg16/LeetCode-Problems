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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode prev = head;
        ListNode curr = head.next;
        
        while(curr != null){
            if(prev.val == curr.val){
                while(curr != null && prev.val == curr.val){
                    curr = curr.next;
                }
                prev.next = curr;
            }
            if(curr == null)prev = curr;
            else{
                prev = curr;
                curr = curr.next;
            }
        }
        
        return head;
    }
}