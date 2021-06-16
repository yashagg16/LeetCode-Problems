class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int maxLen = 0;
        
        while(st < n){
            if(nums[st] == 1){
                int len = 0;
                while(st < n && nums[st] == 1){
                    len++;
                    st++;    
                }
                maxLen = max(maxLen, len);
                
            }
            else{
                st++;
            }
        }
        
        return maxLen;
    }
};