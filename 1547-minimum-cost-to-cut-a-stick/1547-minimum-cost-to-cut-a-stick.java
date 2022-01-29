class Solution {
    public int recur(int[] cut, int i, int j, int[][] dp){
        
        // System.out.println(i + " " + j);
        if(j-i <= 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int min_cost = Integer.MAX_VALUE;
        for(int k=i+1; k<j; k++){
            int cost = cut[j]-cut[i] + recur(cut, i, k, dp) + recur(cut, k, j, dp);
            min_cost = Math.min(min_cost, cost);
        }
        
        // System.out.println("cost i j " + min_cost + " " + i + " " + j);
        dp[i][j] = min_cost;
        return dp[i][j];
    }
    public int minCost(int n, int[] cuts) {
        int k = cuts.length;
        int[] cut = new int[k+2];
        cut[0] = 0;
        cut[k+1] = n;
        
        for(int i=1; i<=k; i++){
            cut[i] = cuts[i-1];
        }
        
        Arrays.sort(cut);
        int sz = k+2;
        
        int[][] dp = new int[sz][sz];
        
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                dp[i][j] = -1;
            }
        }
        
        return recur(cut, 0, sz-1, dp);
    }
}