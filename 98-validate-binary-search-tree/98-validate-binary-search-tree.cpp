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
    bool util(TreeNode* root, TreeNode* a, TreeNode* b){
        if(!root) return true;
        if(a && root->val <= a->val) return false;
        if(b && root->val >= b->val) return false;
        
        bool left = util(root->left, a, root);
        bool right = util(root->right, root, b);
        
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return util(root, NULL, NULL);   
    }
};