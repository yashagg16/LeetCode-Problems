class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransomMap;    
        map<char, int> magazineMap;
        
        for(int i=0; i<ransomNote.size(); i++){
            ransomMap[ransomNote[i]]++;
        }
        
        for(int i=0; i<magazine.size(); i++){
            magazineMap[magazine[i]]++;
        }
        
        for(auto x : ransomMap){
            char ch = x.first; 
            int cnt = x.second;
            
            if(magazineMap.find(ch) == magazineMap.end() || magazineMap[ch] < cnt){
                return false;
            }
        }
        
        return true;
    }
};