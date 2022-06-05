// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        // long long sum = 0;
        // vector<long long> pre_sum(n+1, 0);
        long long total_sum = 0;
        // pre_sum[0] = 0;
        for(int i=1; i<=n; i++){
            total_sum += a[i-1];
        }
        long long sum = 0;
        for(int i=0; i<n; i++){
            long long left_sum = sum;
            sum += a[i];
            long long right_sum = total_sum - sum;
            
            if(left_sum == right_sum) return i+1;
        }
        
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends