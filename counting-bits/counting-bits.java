class Solution {
    public int[] countBits(int n) {
        int[] bitcount = new int[n+1];
        
        for(int i=0; i<=n; i++){
            int count = 0;
            int tmp = i;
            while(tmp > 0){
                count += (tmp%2);
                tmp = tmp/2;
            }
            bitcount[i] = count;
        }
        
        return bitcount;
    }
}