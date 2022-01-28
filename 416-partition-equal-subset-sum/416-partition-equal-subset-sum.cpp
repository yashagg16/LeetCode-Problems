class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int x : nums) sum += x;
        
        if(sum%2 != 0) return false; 
        
        vector<vector<int>> dp(2, vector<int>((sum/2)+1, 0));
        
        dp[0][0] = 1;
        dp[1][0] = 1;
        int curr = 1;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=(sum/2); j++){
                dp[curr][j] = dp[1-curr][j];
                
                if(j >= nums[i]){
                    dp[curr][j] = dp[curr][j] || (dp[1-curr][j-nums[i]]);
                }
            }
            curr = 1-curr;
        }
        
        return dp[1-curr][(sum/2)] ;
    }
};