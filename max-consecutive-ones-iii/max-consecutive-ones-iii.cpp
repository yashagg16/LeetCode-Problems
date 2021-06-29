class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int st = 0, end = 0; end <n; end++){
            if(nums[end] == 0){
                if(k == 0){
                    while(nums[st++] != 0);
                }
                else{
                    k--;
                }
            }
            
            ans = max(ans, end-st+1);
        }
        return ans;
        
    } 
};