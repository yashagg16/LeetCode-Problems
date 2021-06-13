class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //1st search to find if 1 exists or not;
        int i=0;
        for(; i<n; i++){
            if(nums[i] == 1){
                break;
            }
        }
        if(i == n){
            return 1;
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1; //1 because we know that it is not the solution
            }
        }
        
        for(int i=0; i<n; i++){
            //for each element, we can say that now, all the values lie in the range
            //of 1 to n, and hence, if we find this element, we can remove it from the
            //answer by marking its corresponding index as -1.
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        for(int i=0; i<n; i++){
            if (nums[i] > 0) return i+1 ;
        }
        return n+1;
    }
};