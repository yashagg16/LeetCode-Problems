// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string a) {
        int n = a.size();
    int i=0;
    int j=i+1;
    int maxlen=0;
    int st = 0;
    int end = 0;
    while(j<n){
        if(a[i] == a[j]){
            int cnt = 0;
            int x = i;
            int y = j;
            while(x >= 0 && y <n && a[x] == a[y]){
                cnt += 2;
                x--;
                y++;
            }
            if(maxlen < cnt){
                maxlen = cnt;
                st = x+1; 
                end = y-1;
            }
        }

        i++ ; 
        j++;
    }

    i = 0;
    while(i < n){
        int x = i-1;
        int y = i+1;
        int cnt= 1;
        while(x >= 0 && y < n && a[x] == a[y]){
            x--;
            y++;
            cnt += 2;
        }

        if(maxlen < cnt){
            maxlen = cnt;
            st = x+1;
            end = y-1;
        }
        i++;
    }

    return a.substr(st,  end-st+1);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends