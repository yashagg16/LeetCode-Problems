class Solution {
public:
    static bool cmp(string& a, string& b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        
        for(int i=0; i<nums.size(); i++){
            str.push_back(to_string(nums[i]));
        }
        
        sort(str.begin(), str.end(), cmp); 
        
        string ans = "";
        for(int i=0; i<str.size(); i++){
            ans += str[i];
        }
        int i=0;
        for(; i<ans.size()-1; i++){
            if(ans[i] != '0'){
                break;
            }
        }
        
        return ans.substr(i);
    }
};