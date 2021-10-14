class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int currSum = nums[0];
        int maxSum = nums[0];
        
        int i=1;
        
        while(i < n){
            currSum = currSum + nums[i];
            currSum = Math.max(currSum, nums[i]);
            maxSum = Math.max(maxSum, currSum);
            i++;
        }
        
        return maxSum;
    }
}