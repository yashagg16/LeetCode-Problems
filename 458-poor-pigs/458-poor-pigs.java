class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int totalRounds = minutesToTest/minutesToDie;
        totalRounds++;
        int ans = 0;
        int currCount = 1;
        while(currCount < buckets){
            currCount = currCount*totalRounds;
            ans++;
        }
        
        return ans;
    }
}