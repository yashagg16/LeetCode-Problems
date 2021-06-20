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
    public TreeNode findSucc(TreeNode root){
        TreeNode tmp = root;
        
        while(tmp.left != null){
            tmp  =tmp.left;
            
        }
        return tmp;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        //if the root is null, then there is nothing to delete;
        if(root == null){
            return null;
        }
        
        if(root.val < key){
            root.right = deleteNode(root.right, key);
        }
        else if(root.val > key){
            root.left = deleteNode(root.left, key);
        }
        else{
            if(root.left == null && root.right == null) return null;
            if(root.left == null ){
                return root.right;
            }    
            if(root.right == null){
                return root.left;
            }
            
            TreeNode succ = findSucc(root.right);
            root.val = succ.val;
            root.right = deleteNode(root.right, root.val);
        }
        
        return root;
        
        
    }
}