class Solution {
    public boolean canJump(int[] nums) {
        int[] dp = new int[nums.length];
        int maxDist = 0;
        int i=0;
        while(i < nums.length){
            if(i > maxDist){
                return false;
            }
            maxDist = Math.max(maxDist, i + nums[i]);
            if(maxDist >= nums.length-1){
                return true;
            }
            i++;
        }
        
        return false;
    }
}