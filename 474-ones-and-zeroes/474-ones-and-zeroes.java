class Solution {
    public int recur( int m, int n, String[] strs, int[][][] dp, int len, int i){
        if(i == len) return 0;
        
        if(dp[m][n][i] != -1) return dp[m][n][i];
        
        int c1 = 0;
        int c2 = 0;
        for(int j=0; j<strs[i].length(); j++){
            if(strs[i].charAt(j) == '1') c2 ++;
            else c1 ++;
        }
        
        int sol1 = recur(m, n, strs, dp, len, i+1);
        if(m >= c1 && n >= c2){
            sol1 = Math.max(sol1, 1+recur(m-c1, n-c2, strs, dp, len, i+1));
        }
        dp[m][n][i] = sol1;
        return sol1;
    }
    public int findMaxForm(String[] strs, int m, int n) {
        int[][][] dp = new int[m+1][n+1][strs.length+1];
        
        for(int[][] a : dp){
            for(int[] b : a){
                Arrays.fill(b, -1);
            }
        }
        
        return recur(m, n, strs, dp, strs.length, 0);
    }
}