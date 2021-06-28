class Solution {
public:
    vector<vector<int>> moves;
    int dfs(vector<vector<int>> & matrix, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxLen = 1;
        for(vector<int> move : moves){
            int x = i + move[0];
            int y = j + move[1];
            
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            
            if(matrix[x][y] > matrix[i][j]){
                int len = 1+dfs(matrix, x, y, m, n, dp);
                maxLen = max(maxLen, len);
            }
            
        }
        
        dp[i][j] = maxLen;
        return dp[i][j] ; 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j] == -1){
                    int len = dfs(matrix, i, j, m, n, dp);
                    ans = max(len, ans);
                }
            }
        }
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};