class Solution {
    public void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    public void moveZeroes(int[] nums) {
        int i = 0; 
        int j = 0;
        int n = nums.length;
        while(i <= j && j < n){
            if(nums[i] == 0){
                if(nums[j] == 0){
                    j++;
                }
                else{
                    swap(nums, i, j);
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
        }
        
    }
}