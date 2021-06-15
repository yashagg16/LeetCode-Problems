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
    public TreeNode treeMaker(int[] preorder, int st, int end){
        if(st < end) {
            int mid = (st+1+end)/2;
            TreeNode root = new TreeNode(preorder[st]);
            
            int idx = st;
            while(idx+1 <= end && preorder[idx+1] <= preorder[st]){
                idx++;
            }
            TreeNode left = treeMaker(preorder, st+1, idx);
            TreeNode right = treeMaker(preorder, idx+1, end);
            root.left = left;
            root.right = right;
            return root; 
        }
        if(st == end){
            TreeNode x = new TreeNode(preorder[st]);
            return x;
        }
        return null;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        if(preorder.length==0){
            return null;
        }
        int st = 0;
        int end = preorder.length-1;
        
        return treeMaker(preorder, st, end);
    }
}