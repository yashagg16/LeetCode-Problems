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
    public boolean findSum(TreeNode root, int req){
        if(root.left == null && root.right == null){
            if(root.val-req == 0) return true;
            return false;
        }
        
        if(root.left == null){
            return findSum(root.right, req-root.val);
        }
        if(root.right == null){
            return findSum(root.left, req-root.val);
        }
        return findSum(root.right, req-root.val) || findSum(root.left, req-root.val);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        return findSum(root, targetSum);
    }
}