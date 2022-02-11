/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recur(TreeNode* root, int maxHere){
        if(!root) return;
        
        if(root->val >= maxHere){
            cnt++;
            recur(root->left, root->val);
            recur(root->right, root->val);
        }
        else{
            recur(root->left, maxHere);
            recur(root->right, maxHere);
        }
    }
    int goodNodes(TreeNode* root) {
        recur(root, root->val);
        return cnt;
    }
private : 
    int cnt = 0;
};