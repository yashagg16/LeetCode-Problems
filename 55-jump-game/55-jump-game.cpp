class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int maxDist = 0;
        if(nums.size() == 1)return true;
        while(i < nums.size()){
            maxDist = max(maxDist, i+nums[i]);
            if(maxDist >= nums.size()-1) return true;
            if(maxDist <= i) return false;
            
            i++;
        }
        
        if(maxDist >= nums.size()-1) return true;
        
        return false;
    }
};