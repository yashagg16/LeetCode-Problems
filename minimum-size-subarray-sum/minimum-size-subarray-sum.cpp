class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = 1e8;
        int i = 0;
        int j = 0;
        int currSum = nums[0];
        int n = nums.size();
        
        while(i <= j && i < n){
            cout << currSum << endl;
            if(currSum >= target){
                cout << currSum << endl;
                minLen = min(minLen, j-i+1);
                currSum -= nums[i];
                i++;
                if(i == n){
                    break;
                }
                else{
                    if(i > j){
                        j = i;
                        currSum = nums[j];
                    }
                }
            }
            else{
                j++;
                if(j == n) break;
                else{
                    currSum += nums[j];
                }
            }
        }
        if(minLen == 1e8)return 0;
        return minLen;
    }
};