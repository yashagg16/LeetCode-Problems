class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        int tm = 0;
        vector<pair<int,int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int sz = q.size();
            int i = 0;
            int l = 0;
            while(i < sz){
                pair<int, int> pr = q.front(); q.pop();
                
                for(int i=0; i<4; i++){
                    int x = pr.first + moves[i].first;
                    int y = pr.second + moves[i].second;
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        l = 1;
                    }
                }
                i++;
            }
            if(l == 1) tm++;
        }
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if (grid[i][j] == 1) return -1;
        
        return tm;
    }
};