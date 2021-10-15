class Solution {
    public void rotate(int[] nums, int st, int end){
        while(st <= end){
            int tmp = nums[st];
            nums[st] = nums[end];
            nums[end] = tmp;
            st++; end--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k%n;
        rotate(nums, 0, n-1);
        rotate(nums, 0, k-1);
        rotate(nums, k, n-1);
    }
}