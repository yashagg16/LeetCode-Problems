class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        
        // if(nums[0] == 0) return -1;
        
        int lastStep = nums[0];
        
        int maxReachable = nums[0];
        
        int curr= 1;
        int minJumps = 1;        
        while(curr < n-1){
            maxReachable = max(maxReachable, nums[curr]+curr);
            if(lastStep == curr){
                if(maxReachable <= curr) return -1;
                lastStep = maxReachable;
                minJumps++;
            }
            curr++;
        }
        
        return minJumps;
    }
};