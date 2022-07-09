class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        grid[i][j] = 0;
        int ans = 1;
        ans += dfs(grid, i+1, j, n, m);
        ans += dfs(grid, i-1, j, n, m);
        ans += dfs(grid, i, j-1, n, m);
        ans += dfs(grid, i, j+1, n, m);
        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int maxArea = dfs(grid, i, j, n, m);
                    ans = max(ans, maxArea);
                }
            }
        }
        
        return ans;
    }
};