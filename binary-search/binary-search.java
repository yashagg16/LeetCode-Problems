class Solution {
    public int search(int[] nums, int target) {
        int st = 0;
        int end = nums.length-1;
        
        while(st+1 < end){
            int mid = (st+end)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                st = mid;
            }
            else{
                end = mid;
            }
        }
        
        if(nums[st] == target) return st;
        if(nums[end] == target) return end;
        
        return -1;
    }
}