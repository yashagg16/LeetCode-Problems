// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int util(int A[], int n, int sumA, int B[], int m, int sumB){
	    int target = (sumB-sumA)/2;
	    
	    int i=0;
	    int j=0;
	    
	    while(i<n && j<m){
	        int cnt = B[j]-A[i];
	        if(cnt == target){
	            return 1;
	        }
	        else if(cnt < target){
	            j++;
	        }
	        else{
	            i++;
	        }
	    }
	    
	    return -1;
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        sort(A, A+n);
        sort(B, B+m);
        
        int sumA = 0;
        int sumB = 0;
        
        for(int i=0; i<n; i++){
            sumA += A[i];
        }
        
        for(int i=0; i<m; i++){
            sumB += B[i];
        }
        if((sumA+sumB)%2 != 0) return -1;
        int x = util(A, n, sumA, B, m, sumB);
	
	    return x;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends