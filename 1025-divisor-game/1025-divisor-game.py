class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [False for i in range(n+1)]
        
        for i in range(2, n+1) : 
            for j in range(1, i) : 
                if(i%j == 0) : 
                    # print(i, j)
                    dp[i] = dp[i] or (not(dp[i-j]))
                    
        return dp[n]
        