class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        
        int[] ans = new int[n];
        
        int i=0;
        int j=n-1;
        int k=n-1;
        while(i <= j){
            if(Math.abs(nums[i]) > Math.abs(nums[j])){
                ans[k] = nums[i];
                i++;
                k--;
            }
            else{
                ans[k] = nums[j];
                k--;
                j--;
            }
        }
        
        for(i=0; i<n; i++){
            ans[i] *= ans[i];
        }
        
        return ans;
    }
}