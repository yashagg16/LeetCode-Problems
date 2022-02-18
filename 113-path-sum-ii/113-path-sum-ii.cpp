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
private: 
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int req, vector<int> tmp){
        if(root == NULL) return;
        tmp.push_back(root->val);
        req = req-root->val;
        if(root->left == NULL && root->right == NULL){
            if(req == 0){
                ans.push_back(tmp);
                return;
            }
            else{
                return;
            }
        }
        dfs(root->left, req, tmp);
        dfs(root->right, req, tmp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root, targetSum, v);
        return ans;
            
    }
};