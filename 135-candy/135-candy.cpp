class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }
        
        int sum = 0;
        for(int i=n-2; i>=0; i--){
            int tmp = candy[i];
            if(ratings[i] > ratings[i+1]){
                tmp = max(tmp, candy[i+1]+1);
            }
            candy[i] = tmp;
            
        }
        
        for(int i=0; i<n; i++){
            sum += candy[i];
        }
        // cout << endl;
        return sum;
    }
};