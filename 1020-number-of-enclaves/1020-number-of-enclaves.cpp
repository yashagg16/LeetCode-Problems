class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        int ans = 1;
        grid[i][j] = 0;
        
        ans += dfs(grid, i+1, j, n, m);
        ans += dfs(grid, i, j+1, n, m);
        ans += dfs(grid, i-1, j, n, m);
        ans += dfs(grid, i, j-1, n, m);
        
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(grid, i, 0, n, m);
            }
            if(grid[i][m-1] == 1){
                dfs(grid, i, m-1, n, m);
            }
        }
        
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1){
                dfs(grid, 0, i, n, m);
            }
            if(grid[n-1][i] == 1){
                dfs(grid, n-1, i, n, m);
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cnt += dfs(grid, i, j, n, m);
                }
            }
        }
        
        return cnt;
    }
};