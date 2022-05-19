class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        
        int currArea = 1;
        grid[i][j] = 0;
        currArea += dfs(grid, i+1, j, n, m);
        currArea += dfs(grid, i-1, j, n, m);
        currArea += dfs(grid, i, j-1, n, m);
        currArea += dfs(grid, i, j+1, n, m);
        
        return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j, n, m);
                    if(area > maxArea){
                        maxArea = area;
                    }
                }
            }
        }
        
        return maxArea;
    }
};