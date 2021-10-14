class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        
        int i=0;
        int n = nums.length;
        while(i < n-1){
            if(nums[i] == nums[i+1])return true;
            
            i++;
         }
        
        return false;
    }
}