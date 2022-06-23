class Solution {
public:
    void horizontal(vector<vector<int>> matrix, vector<int>& res, int stx, int sty, int endy, int x){
        int i = sty;
        while( i  != endy){
            res.push_back(matrix[stx][i]);
            i += x;
        }
        res.push_back(matrix[stx][i]);   
    }
    
    void vertical(vector<vector<int>> matrix, vector<int>& res, int sty, int stx, int endx, int x){
        int i = stx;
        while(i != endx){
            res.push_back(matrix[i][sty]);
            i += x;
        }
        res.push_back(matrix[i][sty]);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int stx = 0;
        int sty = 0;
        int endx = n-1;
        int endy = m-1;
        
        vector<int> res;
        while(stx <= endx && sty <= endy){
            // cout << stx << " " << endx << " " << sty << " " << endy << endl;
            horizontal(matrix, res, stx, sty, endy, 1);
            stx++;
            if(stx > endx) break;
            
            // cout << stx << " " << endx << " " << sty << " " << endy << endl;
            vertical(matrix, res, endy, stx, endx, 1);
            endy--;
            if(sty > endy) break;
            
            // cout << stx << " " << endx << " " << sty << " " << endy << endl;
            horizontal(matrix, res, endx, endy, sty, -1);
            endx--;
            if(stx > endx) break;
            
            // cout << stx << " " << endx << " " << sty << " " << endy << endl;
            vertical(matrix, res, sty, endx, stx, -1);
            sty++;
            if(sty > endy) break;
        }
        return res;
    }
};