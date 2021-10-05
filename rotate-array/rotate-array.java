class Solution {
    public void rotate(int[] nums, int st, int end){
        while(st <= end){
            int tmp = nums[st];
            nums[st] = nums[end];
            nums[end] = tmp;
            st++;
            end--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        
        if(k > n) k = k%n;
        //rotate the first part;
        rotate(nums, 0, n-k-1);
        
        //rotate the second part;
        rotate(nums, n-k, n-1);
        
        //rotate the entire array;
        rotate(nums, 0, n-1);
    }
}