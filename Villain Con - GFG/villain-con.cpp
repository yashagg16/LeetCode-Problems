// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(vector<int> adj[], vector<int>& maxLen, int i){
        if(maxLen[i] != 0) return maxLen[i];
        
        int curr_len = 0;
        for(int x : adj[i]){
            curr_len = max(dfs(adj, maxLen, x), curr_len);
        }
        curr_len += 1;
        maxLen[i] = curr_len;
        return maxLen[i];
        
    } 
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int> adj[N];
        
        for(int i=0; i<M; i++){
            adj[mat[i][1]-1].push_back(mat[i][0]-1);
        }
        
        vector<int> maxLen(N, 0);
        int max_len = 0;
        for(int i=0; i<N; i++){
            if(maxLen[i] == 0){
                int len = dfs(adj, maxLen, i);
                max_len = max(max_len, len);
                
            }
        }
        
        return max_len;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends