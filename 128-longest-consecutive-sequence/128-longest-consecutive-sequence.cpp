class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> s(nums.begin(), nums.end());
        
        int maxlen = 1;
        for(int x : s){
            if(s.find(x-1) == s.end()){
                int len = 0;
                int curr = x;
                while(s.find(curr) != s.end()){
                    len++;
                    curr++;
                }
                maxlen = max(maxlen, len);
            }
        }
        
        return maxlen ;
    }
};