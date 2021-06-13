class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int minRow = 0;
        int maxRow = r-1;
        int minCol = 0;
        int maxCol = c-1;
        vector<int> sol;
        while(minRow  < maxRow && minCol < maxCol){
            //keeping minRow constant
            for(int i=minCol; i<=maxCol; i++){
                sol.push_back(matrix[minRow][i]);
            }
            minRow++;

            //keeping maxCol constant;
            for(int i=minRow; i<=maxRow; i++){
                sol.push_back(matrix[i][maxCol]);
            }
            maxCol--;

            //keeping maxRow constant
            for(int i=maxCol; i>=minCol; i--){
                sol.push_back(matrix[maxRow][i]);
            }
            maxRow--;

            //keeping minCol constant
            for(int i=maxRow; i>=minRow; i--){
                sol.push_back(matrix[i][minCol]);
            }
            minCol++;
        }
        cout << minRow << " " << maxRow << " " << minCol << " " << maxCol << endl;
        if(minRow == maxRow){
            if(minRow <= r/2){
                while(minCol <= maxCol){
                    sol.push_back(matrix[minRow][minCol]);
                    minCol++;
                }
            }
            else{
                while(maxCol >= minCol){
                    sol.push_back(matrix[minRow][maxCol]);
                    maxCol--;
                }
            }
        }
        if(minCol == maxCol){
            if(minCol <= c/2){
                while(minRow <= maxRow){
                    sol.push_back(matrix[minRow][minCol]);
                    minRow++;
                }
            }
            else{
                while(maxRow >= minRow){
                    sol.push_back(matrix[minRow][maxCol]);
                    maxRow--;
                }
            }
        }
        return sol;
    }
};