class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] arr = new int[nums.length];
        int n = nums.length;
        int i=0;
        int j=n-1;
        int k=n-1;
        while(i < n && j >= 0 && i <= j){
            // System.out.println(i + " " + j + " " + k);
            if(Math.abs(nums[i]) <= Math.abs(nums[j])){
                arr[k--] = nums[j--];
            }
            else{
                arr[k--] = nums[i++];
            }
        }
        
        for( i=0; i<n; i++){
            arr[i] *= arr[i];
        }
        
        return arr;
    }
}