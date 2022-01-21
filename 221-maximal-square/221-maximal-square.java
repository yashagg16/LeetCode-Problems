class Solution {
    public int min(int a, int b, int c){
        if(a <= b && a <= c) return a;
        if(b <= a && b <= c) return b;
        return c;
    }
    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        int[][] dp = new int[n+1][m+1];
        
        int maxLen = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1;
                    maxLen = Math.max(maxLen, dp[i][j]);
                }
            }
        }
        
        
        return maxLen*maxLen;
    }
}