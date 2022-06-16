// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
    //complete the function here
        int mid;
        
        while(h-l > 1){
            mid = (h+l)/2;
            // cout <<A[l]  << " " << A[mid] << " " << A[h] << endl;
            if(A[mid] == key) return mid;
            
            if(A[l] <= A[mid]){
                if(A[l] <= key && key < A[mid]){
                   h = mid; 
                }
                else{
                    l = mid;
                }
            }
            else{
                if(A[mid] < key && key <= A[h]){
                    l = mid;
                }
                else{
                    h = mid;
                }
            }
        }
        
        if(A[h]==key) return h;
        if(A[l] == key) return l;
        return -1;
        
        
        
        
        
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends