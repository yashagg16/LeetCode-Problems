class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;

        int prevSum = nums[0];
        int maxSum = nums[0];
        
        for(int i=1; i<n; i++){
            int currSum = Math.max(prevSum + nums[i], nums[i]);
            maxSum = Math.max(maxSum, currSum);
            prevSum = currSum;
        }
        
        return maxSum;
        
        
    }
}