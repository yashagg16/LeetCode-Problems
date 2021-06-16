class Solution {
    public int[] twoSum(int[] ans, int target) {
        // int[] ans = new int[2];
        int n= ans.length;
        HashMap<Integer, Integer> hmap = new HashMap<>();
        for(int i=0; i<n; i++){
            // cout << ans[i] << endl;

            if(hmap.containsKey(ans[i])){
                hmap.put(ans[i], hmap.get(ans[i])+1);
            }
            else{
                hmap.put(ans[i], 1);
            }
        }
        int num1 = -1;
        int num2 = -1;
        for(int i=0; i<n; i++){
            int req = target - ans[i];
            if(hmap.containsKey(req)){
                if((req == ans[i] && hmap.get(ans[i]) < 2)){
                    continue;
                }
                else{
                    num1 = ans[i];
                    num2 = req;
                }
            }
            else{
                continue;
            }
        }
        System.out.println(num1 + " " + num2);
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0; i<n; i++){
            if(num1 == ans[i] && idx1 == -1 && i != idx2){
                idx1 = i;
            }
            if(num2 == ans[i] && idx2 == -1 && i != idx1){
                idx2 = i;
            }
        }
        return new int[]{idx1, idx2};
    }
}