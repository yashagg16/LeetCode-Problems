class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        int mod = 1e9+7;
        sort(arr.begin(), arr.end());
        
        vector<long long int> dp(n, 1);
        map<int, int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j] == 0){
                    if(st.find(arr[i]/arr[j]) != st.end()){
                        int k = st[arr[i]/arr[j]];
                        dp[i] = ((dp[i]%mod) + ((dp[j]%mod)*(dp[k]%mod)%mod))%mod;
                    }
                }
            }
            
            st[arr[i]] = i;
        }
            
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum = (sum+dp[i])%mod;
        }
        
        return sum;
        }
};