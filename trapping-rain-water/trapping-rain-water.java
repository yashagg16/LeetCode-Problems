class Solution {
    public int trap(int[] height) {
        int n = height.length;
        
        int l = 0;
        int r = height.length-1;
        
        int maxL = 0;
        int maxR = 0;
        
        int ans = 0;
        while(l < r){
            if(height[l] < height[r]){
                ans += Math.max(0, maxL-height[l]);
                if(height[l] >= maxL) maxL = height[l];
                l++;
            }
            else{
                ans += Math.max(0, maxR-height[r]);
                if(height[r] >= maxR) maxR = height[r];
                r--;
            }
        }
        
        return ans;
        
    }
}