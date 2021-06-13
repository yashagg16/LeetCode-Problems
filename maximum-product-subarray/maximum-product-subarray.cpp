class Solution {
public:
    int maxProduct( vector<int> & nums) {
        int n = nums.size();  
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];
        cout << maxProduct << " " << minProduct << endl;
        for(int i=1; i<n; i++){
            int tmp1 = maxProduct;
            int tmp2 = minProduct;
            maxProduct = max({nums[i], nums[i]*tmp1, tmp2*nums[i]});
            minProduct = min({nums[i], tmp2*nums[i], tmp1*nums[i]});
            cout << maxProduct << " " << minProduct << endl;
            ans = max(maxProduct, ans);
        }

        return ans;

    }
};