class Solution {
private : 
    int tot_steps, n, m;
    int st_x,end_x, st_y, end_y;
public: 
    int dfs(vector<vector<int>>& grid, int x, int y, int steps){
        if(x == end_x && y == end_y){
            if(steps == tot_steps) return 1;
            return 0;
        }
        
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) return 0;
        
        grid[x][y] = -1;
        int cnt = 0;
        cnt += dfs(grid, x+1, y, steps+1);
        cnt += dfs(grid, x-1, y, steps+1);
        cnt += dfs(grid, x, y-1, steps+1);
        cnt += dfs(grid, x, y+1, steps+1);
        
        grid[x][y] = 0;
        
        return cnt;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        tot_steps = 0;
        st_x = 0;
        end_x = 0;
        st_y = 0;
        end_y = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) tot_steps++;
                if(grid[i][j] == 1) {
                    st_x = i;
                    st_y = j;
                }
                else if(grid[i][j] == 2){
                    end_x = i;
                    end_y = j;
                    tot_steps++;
                }
            }
        }
        
        return dfs(grid, st_x, st_y, 0);
    }
};