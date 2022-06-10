// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool cmp(vector<int>& a, vector<int>& b){
        // cout << a[0] << " " << a[1] << endl;
        // cout << b[0] << " " << b[1] << endl;
        // cout << endl;
        return a[1] > b[1];
        // cout << "HERE" << endl;
    }
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<vector<int>> v(N, vector<int>(2, 0));
        
        for(int i=0; i<N; i++){
            v[i] = {A[i], B[i]};
        }
        
        sort(v.begin(), v.end(), cmp);
        
        // cout << endl;
        // for(int i=0; i<N; i++){
        //     cout << v[i][0] << " " << v[i][1] << endl;
        // }
        
        int req = T;
        int res = 0;
        int i=0;
        while(i < N && req > 0){
            if(req >= v[i][0]){
                req -= v[i][0];
                res += (v[i][0]*v[i][1]);
            }
            else{
                res += (req*v[i][1]);
                req = 0;
            }
            i++;
        }
        
        return res;
    }
    
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends