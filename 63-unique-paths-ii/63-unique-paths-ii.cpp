class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size(); 
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        
        for(int i=1; i<n; i++){
            if(obstacleGrid[i][0] != 1){
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for(int j=1; j<m; j++){
            if(obstacleGrid[0][j] != 1){
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        // for(vector<int> x : dp){
        //     for(int y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n-1][m-1];
    }
};