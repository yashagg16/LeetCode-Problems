class Solution {
    public void swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    public void sortColors(int[] nums) {
        int n = nums.length;
        int st = 0;
        int mid = 0;
        int end = nums.length-1;
        
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums, st, mid);
                st++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums, end, mid);
                end--;
            }
        }
    }
}