class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        Arrays.fill(dp, (int)1e6);
        dp[0] = 0;
        for(int i=0; i<coins.length; i++){
            for(int j=1; j<=amount; j++){
                if(j >= coins[i]){
                    dp[j] = Math.min(dp[j-coins[i]]+1, dp[j]);
                }
            }
        }
        if(dp[amount] == 1e6) return -1;
        return dp[amount];
    }
}