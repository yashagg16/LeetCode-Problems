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
    public void insertNode(TreeNode root, int val){
        if(root==null){
            root = new TreeNode(val);
            return;
        }
        if(root.val > val){
            if(root.left == null){
                root.left = new TreeNode(val);
            }
            else{
                insertNode(root.left, val);
            }
            return;
        }
        if(root.right == null){
            root.right = new TreeNode(val);
        }
        else{
            insertNode(root.right, val);
        }
        return ;
    }
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null){
            root = new TreeNode(val);
            return root;
        }
        insertNode(root, val);
        return root; 
    }
}