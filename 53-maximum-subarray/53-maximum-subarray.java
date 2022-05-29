class Solution {
    public int max(int a, int b){
        if(a > b) return a;
        return b;
    }
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int maxSum = nums[0];
        int currSum= nums[0];
        
        for(int i=1; i<n; i++){
            currSum = max(currSum+nums[i], nums[i]);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
}