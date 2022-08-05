class Solution {
    private int combinationSumUtil(int[] nums, int target, int[] dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i=0; i<nums.length; i++){
            if(target >= nums[i]){
                ans += combinationSumUtil(nums, target-nums[i], dp);                
            }
        }
        dp[target] = ans;
        return ans;
    }
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target+1];
        for(int i=0; i<dp.length; i++){
            dp[i] = -1;
        }
        return combinationSumUtil(nums, target, dp);
    }
}