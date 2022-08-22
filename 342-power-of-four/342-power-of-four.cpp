class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n == 0) return false;
        while(n%4 == 0){
            n = n/4;
        }
        
        bool ans = false;
        n == 1 ? ans = true : ans =false;
        
        return ans;
    }
};