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
    private int maxVal ;
    public int maxSum(TreeNode root){
        if(root == null) return 0;
        int lSum = maxSum(root.left);
        int rSum = maxSum(root.right);
        int currSum = Math.max(Math.max(lSum, rSum) +root.val, root.val);
        int maxTillHere = Math.max(currSum, lSum+root.val+rSum); 
        
        maxVal = Math.max(maxTillHere, maxVal);
        
        return currSum;    
    }
    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        maxVal = Integer.MIN_VALUE;
        maxSum(root);
        return maxVal;
    }
}