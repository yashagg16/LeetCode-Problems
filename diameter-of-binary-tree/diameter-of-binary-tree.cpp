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
    int maxLen;
    int find(TreeNode* root){
        if(root == NULL) return 0;
        int max_left = find(root->left);
        int max_right = find(root->right);
        
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        if(root->right == NULL){
            maxLen = max(maxLen, max_left+1);
            return max_left+1;
        }
        if(root->left == NULL){
            maxLen = max(maxLen, max_right+1);
            return max_right+1;
        }
        maxLen = max(maxLen, max_left+max_right+2);
        return max(max_left, max_right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxLen = 0;
        find(root);
        return maxLen;
    }   
};