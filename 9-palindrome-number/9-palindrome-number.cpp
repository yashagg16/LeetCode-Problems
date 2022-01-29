class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long a = x;
        long b = 0;
        
        while(x > 0){
            int r = x%10;
            b = 10*b + r;
            x = x/10;
        }
        
        if(a == b) return true;
        return false;
    }
};