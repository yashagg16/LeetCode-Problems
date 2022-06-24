class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int n = strs.size();
        int lastIdx = pre.size();
        for(int i=1; i<n; i++){
            int m = strs[i].size();
            int j = 0;
            
            string temp = "";
            while(j < m &&  j < pre.size()){
                if(strs[i][j] != pre[j]){
                    break;
                }
                else{
                    temp += strs[i][j];
                }
                j++;
            }
            pre = temp;
        }
        
        return pre;
    }
};