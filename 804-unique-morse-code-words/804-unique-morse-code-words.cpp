class Solution {
private:
    map<char, string> mp;
    set<string> st;
    vector<string> code;
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(char i = 'a'; i<='z'; i++){
            mp[i] = code[i-'a'];
        }
        for(int i=0; i<words.size(); i++){
            string tmp = "";
            for(int j=0; j<words[i].size(); j++){
                tmp += mp[words[i][j]];
            }
            st.insert(tmp);
        }
        
        return st.size();
    }
};