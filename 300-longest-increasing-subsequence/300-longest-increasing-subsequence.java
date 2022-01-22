class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n+1];
        
        Arrays.fill(dp, 1);
        dp[0] = 0;
        int res = 1;
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=1; j--){
                if(nums[i-1] > nums[j-1]){
                    dp[i] = Math.max(dp[j]+1, dp[i]);
                }
            }
            
            res = Math.max(res, dp[i]);
        }
        
        return res;
    }
}