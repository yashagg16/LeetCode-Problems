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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        
        return dfs(root, targetSum-root->val);
    }
    
    bool dfs(TreeNode* root, int ts){
        cout << root->val << " " << ts << endl;
        if(root->left == NULL && root->right == NULL){
            if ((ts)==0) return true;
            return false;
        }
        
        if(root->right == NULL){
            return dfs(root->left, ts-root->left->val);
            
        }
        
        if(root->left == NULL){
            return dfs(root->right, ts-root->right->val);
        }
        
        return dfs(root->right, ts-root->right->val) || dfs(root->left, ts-root->left->val);
        
    }
};