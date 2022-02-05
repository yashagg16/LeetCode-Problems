class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        vector<int> maxRight(n, 0);
        maxRight[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], nums[i+1]);
        }
        
        set<int> s;
        s.insert(nums[0]);
        for(int i=1; i<n-1; i++){
            if(nums[i] >= maxRight[i]){
                s.insert(nums[i]);
                continue;
            }
            auto x = s.lower_bound(nums[i]);
            // cout << *x << " " << nums[i] << " " << maxRight[i] << endl;
            if(x == s.begin()){
                if(*x < nums[i]){
                    return true;
                }
                else{
                    s.insert(nums[i]);
                    continue;
                }
            }
            else if(x == s.end()){
                return true;
            }
            else{
                --x;
                if(*x < nums[i]) return true;
                else return false;
            }
        }
        
        return false;
    }
};