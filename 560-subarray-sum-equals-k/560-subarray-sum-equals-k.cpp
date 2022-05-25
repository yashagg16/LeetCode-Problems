class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                // cout << sum-k << " " << mp[sum-k] << endl;
                cnt += mp[sum-k];
            }
            mp[sum] += 1;
        }
        
        return cnt;
    }
};