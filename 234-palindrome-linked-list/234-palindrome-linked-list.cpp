/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* nd1 = head;
        ListNode* nd2 = head;
        
        while(nd2 && nd2->next){
            nd1 = nd1->next;
            nd2 = nd2->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* tmp = nd1;
        
        while(tmp){
            ListNode* x = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = x;
        }
        
        while(prev && head){
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        
        return true;
    }
};