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
    public boolean isPalindrome(ListNode head) {
        ListNode head2 = null;
        ListNode last = null;
        ListNode tmp2 = head;
        while(tmp2 != null){
            if(head2 == null){
                head2 = new ListNode(tmp2.val);
                last = head2;
            }else{
                last.next = new ListNode(tmp2.val);
                last = last.next;
            }
            tmp2 = tmp2.next;
        }
        tmp2 = head2; 
        while(tmp2 != null){
            System.out.print(tmp2.val + " ");
            tmp2 = tmp2.next;
        }
        System.out.println();
        ListNode tmp = head;
        ListNode prev = null;
        
        while(tmp != null){
            ListNode x = tmp.next;
            tmp.next = prev;
            prev = tmp;
            tmp = x; 
        }
        
        while(prev != null && head2 != null){
            System.out.println(prev.val + " " + head2.val);
            if(prev.val != head2.val) return false;
            prev = prev.next;
            head2 = head2.next;
        }
        
        return true;
    }
}