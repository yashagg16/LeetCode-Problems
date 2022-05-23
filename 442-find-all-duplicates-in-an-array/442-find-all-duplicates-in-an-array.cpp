class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            int idx = nums[i];
            if(idx < 0) idx *= -1;
            if(nums[idx-1] < 0) res.push_back(idx);
            else nums[idx-1] *= -1;
        }
        
        return res;
    }
};