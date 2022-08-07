mod = 1000000007
def checkChar(x) :
    if(x == 0) : 
        return [1]
    elif(x == 1) :
        return [0, 2]
    elif(x == 2) :
        return [0, 1, 3, 4]
    elif(x == 3) :
        return [2, 4]
    else :
        return [0]
        
def util(n, sz, lis, dp) :
    if(sz == n) :
        return 1;
    # print(len(dp), " ", len(dp[0]))
    ans = 0
    for x in lis : 
        new_lis = checkChar(x)
        # print(sz, " ", x)
        if(dp[sz][x] != -1) :
            ans += dp[sz][x]
        else :
            dp[sz][x] = util(n, sz+1, new_lis, dp)
            ans = (ans + dp[sz][x])%mod
    
    return ans

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        lis = [0, 1, 2, 3, 4]
        dp=[[-1 for i in range(6)] for j in range(n+1)]
        # print(dp)
        return util(n, 0, lis, dp)