class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        int x1=0;
        int x2=m-1;
        
        int y1=0;
        int y2=n-1;
        vector<int>res;
        while(x1 <= x2 && y1 <= y2){
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            for(int i=y1; i<=y2; i++){ 
                cout << matrix[x1][i] << " ";
                res.push_back(matrix[x1][i]);
            }
            x1++;
            if(x1 > x2) break; 
            for(int i=x1; i<=x2; i++){
                cout << matrix[i][y2] << " ";
                res.push_back(matrix[i][y2]);
            }
            // cout << "end2" << endl;
            y2--;
            if(y1 > y2) break;
            // cout << y2 << " " << y1 << endl;
            for(int i=y2; i>=y1; i--){
                cout << matrix[x2][i] << " ";
                res.push_back(matrix[x2][i]);
            }
            // cout << "end3" << endl;
            x2--;
            if(x1 > x2) break;
            // cout << x1 << " " << x2 << endl;
            for(int i=x2; i>=x1; i--){
                cout << matrix[i][y1] << " ";
                res.push_back(matrix[i][y1]);
            }
            // cout << "end4" << endl;
            y1++;
            if(y1 > y2) break;
            // cout << endl;
        }
        
        return res;
        
    }
};