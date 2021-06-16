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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        
        ListNode ans = null;
        ListNode last = null;
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                if(ans == null){
                    ans = new ListNode(l1.val);
                    last = ans;
                }
                else{
                    last.next = new ListNode(l1.val);
                    last = last.next;
                }
                l1 = l1.next;
            }
            else{
                if(ans == null){
                    ans = new ListNode(l2.val);
                    last = ans;
                }
                else{
                    last.next = new ListNode(l2.val);
                    last = last.next;
                }
                l2 = l2.next;
            }
        }
        
        while(l1 != null){
            if(ans == null){
                ans = new ListNode(l1.val);
                last = ans;
            }
            else{
                last.next = new ListNode(l1.val);
                last = last.next;
            }
            l1 = l1.next;
        }
        
        while(l2 != null){
            if(ans == null){
                ans = new ListNode(l2.val);
                last = ans;
            }
            else{
                last.next = new ListNode(l2.val);
                last = last.next;
            }
            l2 = l2.next;
            
        }
        
        return ans;
    }
}