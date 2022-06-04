// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // coode here 
        int st = 0;
        int mid = 0;
        int end = n-1;
        
        while(mid <= end ){
            if(arr[mid] == 0){
                swap(arr[st],  arr[mid]) ;
                st++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++; 
            }
            else{
                swap(arr[end], arr[mid]);
                end--;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends