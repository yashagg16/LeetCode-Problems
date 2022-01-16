class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1, "");
        
        dp[1] = "1";
        
        for(int i=2; i<=n; i++){
            string x = dp[i-1];
            int j = 0;
            int cnt = 1;
            string res ="";
            while(j < x.size()-1){
                if(x[j] == x[j+1]){
                    cnt++;
                }
                else{
                    res = res + to_string(cnt) + x[j];
                    cnt = 1;
                }
                
                j++;
            }
            
            if(cnt ==1){
                res = res + "1" + x[j];
            }
            else{
                res = res + to_string(cnt) + x[j];
            }
            
            dp[i] = res;
        }
        
        // for(int i=1; i<=n; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[n];
    }
};