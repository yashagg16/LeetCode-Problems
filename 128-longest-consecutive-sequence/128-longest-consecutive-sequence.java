class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;
        HashSet<Integer> hset = new HashSet<>();
        for(int num : nums){
            hset.add(num);
        }
        int maxlen = 0;
        for(int num : hset){
            if(!hset.contains(num-1)){
                int curr = num;
                int len = 0;
                while(hset.contains(curr)){
                    curr++;
                    len++;
                }
                maxlen = Math.max(maxlen, len);
            }
        }
        
        return maxlen;
    }
}