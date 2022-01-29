class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        
        while(i < j && j < n){
            if(nums[i] == 0){
                if(nums[j] == 0){
                    j++;
                }
                else{
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }
            }
            else{
                if(nums[j] == 0){
                    i++;
                    j++;
                }
                else{
                    i++;
                    if(i == j) j = i+1;
                }
            }
        }
    }
};