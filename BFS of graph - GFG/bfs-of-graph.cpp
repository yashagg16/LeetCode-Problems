// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
    
        vector<int> v(V, 0);
        vector<int> lst;
        queue<int> q;
        q.push(0);
        v[0] = 1;
        while(!q.empty()){
            int x =  q.front(); q.pop();
            lst.push_back(x);
            // cout << "x " << x << endl;
            for(int y : adj[x]){
                // cout << "y " << y << endl;
                if(v[y] == 0){
                    v[y] = 1;
                    q.push(y);
                }
            }
        }
        return lst; 
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends