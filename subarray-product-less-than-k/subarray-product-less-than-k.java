class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k <= 1) return 0;
        int n = nums.length;
        int st = 0;
        int prod = 1;
        int len = 0;
        for(int i=0; i<n; i++){
            prod *= nums[i];
            
            while(prod>=k)  prod /= nums[st++];
            
            len += (i-st+1);
        }
        
        return len;
    }
}