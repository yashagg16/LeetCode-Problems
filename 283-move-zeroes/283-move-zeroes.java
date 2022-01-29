class Solution {
    public void swap(int[] a, int b, int c){
        int tmp = a[b];
        a[b] = a[c];
        a[c] = tmp;
    }
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        
        int i = 0;
        int j = 1;
        
        while(i < j && j < n){
            if(nums[i] == 0){
                if(nums[j] == 0){
                    j++;
                }
                else{
                    swap(nums, i, j);
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
                    if(i == j){
                        j = i+1;
                    }
                }
            }
        }
    }
}