// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
        double findAns(double st, double end, double magnets[], int n){
            double mid;
            
            for(int i=0; i<100; i++){
                mid = (st+end)/2;
                // cout << st << " " << mid << " " << end << endl;
                
                double lF = 0;
                double rF = 0;
                for(int j=0; j<n; j++){
                    if(magnets[j] <= mid){
                        lF += 1/(mid-magnets[j]);
                    }
                    else{
                        rF += 1/(magnets[j]-mid);
                    }
                }
                // cout << lF << " " << rF << endl;
                if(lF == rF) return mid;
                else if(lF > rF) st = mid;
                else end = mid;
            }
            
            return mid;
        }
        
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
    
        for(int i=0; i<n-1; i++){
            double st = magnets[i];
            double end = magnets[i+1];
            double ans = findAns(st, end, magnets, n);
            getAnswer[i] = ans;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends