class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currPos = 0;
        int maxReachable = 0;
        int jumps = 0;
        int currMaxPos = 0;
        while(currPos < n-1){
            maxReachable = max(maxReachable, nums[currPos]+currPos);
            if(currMaxPos == currPos) {
                currMaxPos = maxReachable;
                jumps++;
            }
            currPos++;
        }
        
        return jumps;
    }
};