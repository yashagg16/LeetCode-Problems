// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> res;
	    void recur(string S, string ans){
	        if(0 == S.size()){
	            res.push_back(ans);
	            return;
	        }
	        
	        for(int i=0; i<S.size(); i++){
	            string lft = S.substr(0, i);
	            string rgt = S.substr(i+1);
	            string tmp = ans + S[i];
	            recur(lft+rgt, tmp);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(), S.end());
		    string answer = "";
		    
		    recur(S, answer);
		    
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends