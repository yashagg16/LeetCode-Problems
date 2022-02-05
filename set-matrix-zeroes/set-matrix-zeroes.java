class Solution {
    public void setZeroes(int[][] matrix) {
        int r0 = 0;
        int c0 = 0;
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0) {
                c0 = 1;
                break;
            }
        }
        
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                r0 = 1;
                break;
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(r0 == 1){
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        }
        if(c0 == 1){
            for(int i=0; i<m; i++) matrix[0][i] = 0;
        }
        
        
    }
}