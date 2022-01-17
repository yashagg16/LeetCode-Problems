class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int i =0;
        vector<vector<int>> sol;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        while(i < n-2){
            int a = arr[i];
            
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int b = arr[j];
                int c = arr[k];
                
                if(a+b+c == 0){
                    sol.push_back({a, b, c});
                    while(j<n && arr[j] == b) j++;
                    while(k>=0 && arr[k] == c) k--;
                }
                else if(a+b+c < 0){
                    while(j<n && arr[j] == b) j++;
                }
                else{
                    while(k>=0 && arr[k] == c) k--;
                }
                
            }
            
            while(i < n && arr[i] == a) i++;
        }
        
        return sol;
    }
};