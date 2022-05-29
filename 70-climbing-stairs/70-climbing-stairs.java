class Solution {
    public int climbStairs(int n) {
        int prev_one = 1;
        int prev_two = 2;
        if(n == 1) return prev_one;
        if(n == 2) return prev_two;
        
        for(int i=3; i<=n; i++){
            int new_val = prev_one+prev_two;
            prev_one = prev_two;
            prev_two = new_val;
        }
        
        return prev_two;
    }
}