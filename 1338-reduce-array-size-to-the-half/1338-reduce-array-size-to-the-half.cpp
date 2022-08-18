class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<int> ar;
        
        for(auto x : mp){
            ar.push_back(x.second);
        }
        
        // cout << "here" << endl;
        sort(ar.begin(), ar.end());
        
        int cnt = 0;
        int ele = 0;
        int i = ar.size()-1;
        
        while(i >= 0){
            cout << ar[i] << endl;
            cnt += ar[i];
            ele++;
            if(cnt >= n/2){
                break;
            }
            i--;
        }
        
        return ele;
    }
};