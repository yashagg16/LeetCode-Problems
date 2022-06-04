// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n == 1) return 0;
        if(arr[0] == 0) return -1;
        
        int maxLastPos = arr[0];
        int maxOverallPos = arr[0];
        int jumps = 1;
        int i=1;
        
        while(i < n-1){
            maxOverallPos = max(maxOverallPos, arr[i]+i);
            
            if(maxLastPos == i){
                if(maxOverallPos <= i) return -1;
                
                maxLastPos =  maxOverallPos;
                jumps++;
            }
            i++;
        }
        
        return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends