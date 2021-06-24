class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if(n == 1) return 0;
        if(nums[0] == 0) return -1;
        int maxReach = nums[0];
        int minJump = 1;
        int lastStep = nums[0];
        int i=1;
        
        while(i < n-1){
            maxReach = Math.max(maxReach, nums[i] + i);
            lastStep--;
            
            if(lastStep == 0){
                minJump++;
                if(i >= maxReach) return -1;
                lastStep = maxReach - i;
            }
            i++;
        }
        
        return minJump;
    }
}