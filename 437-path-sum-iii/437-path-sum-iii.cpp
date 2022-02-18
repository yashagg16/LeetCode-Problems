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
    int dfs(TreeNode* root, int req, int x){
        if(root == NULL) return 0;
        
        int ans = 0;
        if(x == 0){
            ans += dfs(root->left, req, x);
            ans += dfs(root->right, req, x);
        }
        
        x = 1;
        req -= root->val;
        if(0 == req){
            ans ++;
        }
        ans += dfs(root->left, req, x);
        ans += dfs(root->right, req, x);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};