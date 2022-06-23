class Solution:
    def isHappy(self, n: int) -> bool:
        hashSet = set()
        while((n != 1) and (n not in hashSet)) :
            hashSet.add(n)
            temp = 0
            while(n > 0) : 
                temp += (n%10)*(n%10)
                n = n//10
            
            n = temp
            
        return n == 1
            