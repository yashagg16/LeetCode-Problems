//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int>& vis, int i, int par){
        vis[i] = 1;
        for(int x : adj[i]){
            if(x == par) continue;
            if(vis[x] == 1) return true;
            
            bool res = dfs(adj, vis, x, i);
            if(res)return true;
        }
        vis[i] = 2;
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        /*
            make a queue for the bfs
        */
        
        queue<vector<int>> q;
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                q.push({i,-1});
                
                while(!q.empty()){
                    vector<int> top = q.front(); q.pop();
                    int idx = top[0];
                    int par = top[1];
                    vis[idx] = 1; 
                    for(int k : adj[idx]){
                        if(k == par) continue;
                        if(vis[k] == 1) return true; 
                        q.push({k, idx});
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends