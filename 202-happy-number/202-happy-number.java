class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> hset = new HashSet<>();
        
        while(n != 1 && !hset.contains(n)){
            int temp = 0;
            hset.add(n);
            while(n > 0){
                temp += (n%10)*(n%10);
                n /= 10;
            }
            n = temp;
        }
        
        return n == 1;
    }
}