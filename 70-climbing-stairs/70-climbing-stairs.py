class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [1, 1, 2]
        
        for i in range(3, n+1) : 
            val = dp[i-1] + dp[i-2]
            dp.append(val)
            
        return dp[n]
        
        