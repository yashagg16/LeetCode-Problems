class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int cnt = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] == majority) cnt++;
            else cnt--;
            
            if(cnt == 0){
                majority = nums[i];
                cnt =1;
            }
        }
        
        return majority;
    }
};