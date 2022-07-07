class NumMatrix {
    public int[][] sum_matrix;
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        sum_matrix = new int[n+1][m+1]; 
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                sum_matrix[i][j] = sum_matrix[i-1][j] + sum_matrix[i][j-1] - sum_matrix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         System.out.print(sum_matrix[i][j] + " ");
        //     }
        //     System.out.println();
        // }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        
        return sum_matrix[row2][col2]-sum_matrix[row1][col2]-sum_matrix[row2][col1] + sum_matrix[row1][col1] ;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */