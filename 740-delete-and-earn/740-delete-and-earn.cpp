class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        vector<int> dp(10001, 0);
        
        for(int i=0; i<nums.size(); i++){
            cnt[nums[i]]++;
            // cout << nums[i] << " " << cnt[nums[i]] << endl;
        }
        
        dp[0] = 0;
        dp[1] = cnt[1]*1;
        // cout << "HERE" << endl;
        for(int i=2; i<=10000; i++){
            if(cnt[i] == 0){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);
            }
            // cout << i << " " << cnt[i] << " " << dp[i] << endl;
        }
        // cout << "HERE" << endl;
        // for(int i=0; i<=10; i++){
        //     cout << i << " " << dp[i] << " " << cnt[i] << endl;
        // }
        return dp[10000];
    }
};