class Solution {
    public int trap(int[] height) {
        int left_max = 0;
        int right_max = 0;
        int n = height.length;
        
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l < r){
            if(height[l] < height[r]){
                ans += Math.max(left_max-height[l], 0);
                left_max = Math.max(left_max, height[l]);
                l++;
            }
            else{
                ans += Math.max(right_max-height[r], 0);
                right_max = Math.max(right_max, height[r]);
                r--;
            }
        }
        return ans;
    }
}