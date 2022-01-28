class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e6);
        dp[0] = 0;
        for(int i=0; i<coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j >= coins[i]){
                    dp[j] = min(dp[j-coins[i]] + 1, dp[j]);
                }
            }
        }
        
        // for(int i=0; i<=amount; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        
        if(dp[amount] == 1e6) return -1;
        return dp[amount];
    }
};