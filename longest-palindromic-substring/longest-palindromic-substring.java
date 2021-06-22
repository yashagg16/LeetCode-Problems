class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int[][] dp = new int[n+1][n+1];
        
        int stIdx = 0;
        int endIdx = 0;
        int maxLen = 1;
        
        
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int len = 1; len < n; len++){
            int x = 0;
            int y = len;
            
            while(x<n && y<n){
                if(s.charAt(x) == s.charAt(y)){
                    if(x+1 <= y-1){
                        if(dp[x+1][y-1] > 0){
                            dp[x][y] = dp[x+1][y-1] + 2;
                            if(maxLen < dp[x][y]){
                                maxLen = dp[x][y]; 
                                stIdx = x;
                                endIdx = y;
                            }
                        }
                        else{
                            dp[x][y] = 0;
                        }
                    }
                    else{
                        dp[x][y] = 2;
                        if(maxLen < dp[x][y]){
                            maxLen = dp[x][y];
                            stIdx = x; 
                            endIdx = y;
                        }
                    }
                }
                else{
                    dp[x][y] = 0;
                }
                x++; y++;
            }
        }
        return s.substring(stIdx, endIdx+1);
    }
}