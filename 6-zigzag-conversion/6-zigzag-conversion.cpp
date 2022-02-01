class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows >= s.size() || numRows == 1) return s;
        int i = 0;
        map<int, string> mp;
        int mv = 1;
        int dir = 1;
        int row = 0;
        while(i < s.size()){
            mp[row] += s[i];
            if(row == 0 && dir == -1){
                dir = 1;
            }
            else if(row == numRows-1 && dir == 1){
                dir = -1;
            }
            
            row = row + dir;
            i++;
        }
        
        string ans = "";
        for(auto x : mp){
            ans += x.second;
        }
        
        return ans;
    }
};