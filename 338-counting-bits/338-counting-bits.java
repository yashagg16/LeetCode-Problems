class Solution {
    public int[] countBits(int n) {
        int[] dp = new int[n+1];
        if(n == 0) return dp;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i/2] + dp[i%2];
        }
        
        return dp;
        
    }
}