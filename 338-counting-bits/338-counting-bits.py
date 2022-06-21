class Solution:
    def countBits(self, n: int) -> List[int]:
        if(n == 0) : 
            return [0]
        if(n == 1) : 
            return [0,1]
        
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        for i in range(2, n+1) : 
            dp[i] = dp[(i//2)] + dp[i%2]
            
        
        return dp
        
        
        
        
        
        
        
        
        
# 0 = 0 
# 1 = 1  0 
# 2 = 1  1 
# 3 = 2  2 (3/2) + (3%2) = dp(1) + dp(1)
# 4 = 1  1 (4/2) + (4%2) = dp(2) + dp(0)
# 5 = 2  2 (5/2) + (5%2) = dp(2) + dp(1)
# 6 = 2  2 (6/2) + (6%2)
# 7 = 3  3 (7/2) + (7%2) = dp(3) + dp(1)
# 8 = 1  1
# 9 = 2  
# 10 =2 
# 11 =3 
# 12 =2 
# 13 =3 
# 14 =2 
# 15 =1 
# 16 =1 