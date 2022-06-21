class Solution:
    def divisorGame(self, n: int) -> bool:
        if (n == 1) : 
            return False
        lst = [0,0]
        
        for i in range(2, n+1) :
            res = False
            for j in range(1, i) :
                if(i%j == 0) : 
                    res = res or (not(lst[i-j]))
            lst.append(res)
            
        return lst[n]
        
        
# 0 < x < n  and n%x == 0
#     n = n-x
    
# lose the game if not possible 
# true = Alice wins
# false = Alice loses

# f(1)
# false

# f(2)
# !f(1)
# true 

# f(3)
# !f(2)
# false

# f(4)
# !f(3) || !f(2)
# true