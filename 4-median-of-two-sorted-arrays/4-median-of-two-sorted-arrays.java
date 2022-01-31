class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums2.length < nums1.length) return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.length;
        int m = nums2.length;
        
        int l = 0;
        int h = n;
        
        while(l <= h){
            int c1 = (l + h) >> 1;
            int c2 = ((n+m+1)/2) - (c1);
            
            int l1 = (c1 == 0) ? Integer.MIN_VALUE : nums1[c1-1];
            int l2 = (c2 == 0) ? Integer.MIN_VALUE : nums2[c2-1];
            
            int r1 = (c1 == n) ? Integer.MAX_VALUE : nums1[c1];
            int r2 = (c2 == m) ? Integer.MAX_VALUE : nums2[c2];
            
            System.out.println(l1 + " " + l2 + " " + r1 + " " + r2);
            if(l1 <= r2 && l2 <= r1){
                return (n+m)%2 == 0 ? (double)(Math.max(l1, l2) + Math.min(r1,r2))/2.0 : Math.max(l1, l2);
            }
            else if(l1 > r2){
                h = c1-1;
            }
            else{
                l = c1+1;
            }
        }
        
        return 0.0;
    }
}