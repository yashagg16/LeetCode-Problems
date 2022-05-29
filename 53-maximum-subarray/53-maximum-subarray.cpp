class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prevSum = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++){
            prevSum = max(nums[i] + prevSum, nums[i]);
            
            maxSum = max(maxSum, prevSum);
        }
        
        return maxSum;
    }
};