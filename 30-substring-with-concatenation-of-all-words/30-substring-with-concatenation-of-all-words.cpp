class Solution {
    private: 
    map<string, int> mp;
    int n;
    int k;
    int len;
    int tot_len;
    
    public:
    void getResult(int i, string s, vector<int>& ans){
        map<string, int> curr_mp;
        int tmp_k = 0;
        bool  excess_word = false;
        
        for(int j=i; j<=n-len; j+=len){
            string sub = s.substr(j, len);
            
            if(mp.find(sub) == mp.end()){
                curr_mp.clear();
                tmp_k = 0;
                excess_word = false;
                i = j+len;
            }
            else{
                while(j-i == tot_len || excess_word){
                    string word = s.substr(i, len);
                    i += len;
                    
                    curr_mp[word]--;
                    
                    if(curr_mp[word] >= mp[word]){
                        excess_word = false;
                    }
                    else{
                        tmp_k--;
                    }
                }
                
                curr_mp[sub]++;
                if(curr_mp[sub] <= mp[sub]){
                    tmp_k++;
                }
                else{
                    excess_word = true;
                }
                
                if(tmp_k == k && !excess_word){
                    ans.push_back(i);
                }
            }
        }
        
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        k = words.size();
        len = words[0].size();
        
        tot_len = k*len;
        
        for(string word : words) mp[word]++;
        
        vector<int> ans;
        
        for(int i=0; i<len; i++){
            getResult(i, s, ans);
        }
        
        return ans;
    }
};