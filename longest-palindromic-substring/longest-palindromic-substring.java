class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int[][] dp = new int[n+1][n+1];
        
        for(int len=0; len<n; len++){
            int x = 0;
            int y = x + len;
            // System.out.println(x + " " + y);
            while(x < n && y < n){
                // System.out.println("x and y" + x + " " + y);
                if(x == y){
                    dp[x][y] = 1;
                }
                else{
                    if(x == y-1){
                        if(s.charAt(x) == s.charAt(y)){
                            dp[x][y] = 1;
                        }
                        else{
                            dp[x][y] = 0;
                        }
                    }
                    else{
                        if(s.charAt(x) == s.charAt(y)){
                            dp[x][y] = dp[x+1][y-1];
                        }
                        else{
                            dp[x][y] = 0;
                        }
                    }
                }
                x++; y++;
            }
        }
        
        int stIdx = 0;
        int endIdx = 0;
        int maxLen = 0;
        
        for(int len=0; len<n; len++){
            int x = 0;
            int y = x + len;
            
            while(x < n && y < n){
                if(x == y){
                    stIdx = x;
                    endIdx = x;
                    maxLen = 1;
                }
                else{
                    if(dp[x][y] == 1){
                        if(maxLen < (y-x+1)){
                            stIdx = x;
                            endIdx = y;
                            maxLen = y-x+1;
                        }
                    }
                }
                x++; y++;
            }
        }
        System.out.println(stIdx + " " + endIdx + " " + maxLen);
        return s.substring(stIdx, endIdx+1);
    }
}