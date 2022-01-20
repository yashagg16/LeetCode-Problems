// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool srt(pair<int, int> a, pair<int, int> b){
        if(b.second != a.second) return a.second < b.second;
        return a.first<b.first;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int, int> grps[n];
        
        for(int i=0; i<n; i++){
            grps[i].first = start[i];
            grps[i].second = end[i];
        }
        
        sort(grps, grps+n, srt);
        
        int end_time = grps[0].second;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(grps[i].first > end_time){
                cnt++;
                end_time = grps[i].second;
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends