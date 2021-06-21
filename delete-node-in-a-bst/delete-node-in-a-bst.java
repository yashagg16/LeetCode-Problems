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
    public TreeNode findSuc(TreeNode root){
        TreeNode tmp = root;
        while(tmp.left != null){
            tmp = tmp.left;
        }
        return tmp;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        
        if(root.val < key){
            root.right = deleteNode(root.right, key);
        }
        else if(root.val > key){
            root.left = deleteNode(root.left, key);
        }
        else{
            if(root.left == null && root.right == null) return null;
            
            if(root.left == null) return root.right;
            if(root.right == null) return root.left;
        
            TreeNode suc = findSuc(root.right);
            root.val = suc.val;
            root.right = deleteNode(root.right, suc.val);
        }
        return root;
        
    }
}