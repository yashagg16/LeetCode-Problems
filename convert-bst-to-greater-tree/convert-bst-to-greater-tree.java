/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans  = 0;
    public void dfs(TreeNode root){
        if(root == null){
            return;
        }
        
        dfs(root.right);
        root.val += ans;
        ans= root.val;
        dfs(root.left);
    }
    public TreeNode convertBST(TreeNode root) {
        if(root == null){
            return root;
        }
        dfs(root);
        return root;
    }
}