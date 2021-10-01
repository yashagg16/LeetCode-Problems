class Solution {
    public int search(int[] nums, int target) {
        int st = 0;
        int end = nums.length-1;
        
        int mid;
        
        while(st + 1 < end){
            mid = (st + end)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid;
            }
            else {
                st = mid;
            }
        }
        
        if(nums[st] == target) return st;
        if(nums[end] == target) return  end;
        
        return -1;
    }
}