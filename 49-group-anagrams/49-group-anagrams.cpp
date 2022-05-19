class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mp;
        int n = strs.size();
        for(int i=0; i<n; i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if(mp.find(sorted) == mp.end()){
                mp[sorted] = {i};
            }
            else{
                mp[sorted].push_back(i);
            }
        }
        
        vector<vector<string>> res;
        
        for(auto idx: mp){
            string str = idx.first;
            vector<int> y = idx.second;
            vector<string> ans;
            for(int i: y){
                ans.push_back(strs[i]);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};