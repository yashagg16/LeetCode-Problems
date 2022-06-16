// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int i=0;
        int j=n-1;
        int mid;
        while(j-i > 1){
            mid = (j+i)/2;
            // cout << i << " " << mid << " " << j << endl;
            if(arr[mid] == k) return mid;
            if(arr[mid] < k)i = mid;
            else j  = mid;
        }
        
        if(arr[j] == k) return j;
        else if(arr[i] == k) return i;
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}
  // } Driver Code Ends