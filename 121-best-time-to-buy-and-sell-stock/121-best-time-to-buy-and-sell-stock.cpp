class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMax = 0;
        int minPrice = prices[0];
        int n = prices.size();
        
        for(int i=0; i<n; i++){
            if(prices[i] > minPrice){
                currMax = max(currMax, prices[i]-minPrice);
            }
            else{
                minPrice = prices[i];
            }
        }
        
        return currMax;
    }
};