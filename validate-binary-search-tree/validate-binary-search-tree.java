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
    TreeNode pre;
    public boolean checkValid(TreeNode root){
        if(root == null){
            return true;
        }
        
        boolean left = checkValid(root.left);
        if(left == false){
            return false;
        }
        if(pre != null && (pre.val >= root.val)){
            return false;
        }
        pre =root;
        return checkValid(root.right);
    }
    public boolean isValidBST(TreeNode root) {
        pre = null;
        
        return checkValid(root);
        
    }
}