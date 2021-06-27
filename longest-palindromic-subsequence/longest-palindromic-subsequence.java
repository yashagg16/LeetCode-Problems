class Solution {
    public int solve(String s, int st, int end, int[][] dp){
        if(st > end) return 0;
        if(st == end) return 1;
        
        if(dp[st][end] != 0) return dp[st][end];
        
        if(s.charAt(st) == s.charAt(end)){
            return dp[st][end] = 2 + solve(s, st+1, end-1, dp);
        }
        else{
            return dp[st][end] = Math.max(solve(s, st+1, end, dp), solve(s, st, end-1, dp));
        }
    }
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n+1][n+1];
        
        return solve(s, 0, n-1, dp);
    }
}