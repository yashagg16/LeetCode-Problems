class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        ArrayList<List<Integer>> arlist = new ArrayList<>();
        Arrays.sort(nums);
        int i=0;
        
        if(n < 3){
            return arlist;
        }
        while(i < n-2){
            int num1 = nums[i];
            int j = i+1;
            int k = n-1;
        
            while(j < k){
                int num2 = nums[j];
                int num3 = nums[k];
                int sum = num1 + num2 + num3;
                if(sum == 0){
                    ArrayList<Integer> list = new ArrayList<>();
                    list.add(num1);
                    list.add(num2);
                    list.add(num3);
                    arlist.add(list);
                    while(j < n && nums[j] == num2) j++;
                    while(k >= 0 && nums[k] == num3) k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
            
            while(i < n-2 && nums[i] == num1) i++;
        }
        return arlist;
    }
}