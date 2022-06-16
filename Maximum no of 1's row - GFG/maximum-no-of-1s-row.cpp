// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &A, int N, int M)
        {
            // your code here
            int max_cnt = 0;
            int idx = 0;
            for(int i=0; i<N; i++){
                int st = 0;
                int end = M-1;
                int mid;
                int cnt = 0;
                while(end-st>1){
                    mid = (st+end)/2;
                    // cout << st << " " << mid << " " << end << endl;
                    if(A[i][mid] == 1){
                        cnt += (end-mid);
                        end = mid;
                    }
                    else{
                        st = mid;
                    }
                }
                if(A[i][end] == 1) cnt++;
                if(A[i][st] == 1) cnt++;
                // cout << "val " << i << " " << cnt << " " << max_cnt << endl;
                if(cnt > max_cnt){
                    max_cnt = cnt;
                    idx = i;
                }
                
                
            }
            
            return idx;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends