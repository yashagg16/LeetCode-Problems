class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        
        int i=0;
        int j=n-1;
        
        int idx1 = -1;
        int idx2 = -1;
        while(i < j){
            if(numbers[i] + numbers[j] > target){
                j--;
            }
            else if(numbers[i] + numbers[j] == target){
                idx1 = i;
                idx2 = j;
                break;
            }
            else {
                i++;
            }
        }
        return new int[]{idx1+1, idx2+1};
    }
}