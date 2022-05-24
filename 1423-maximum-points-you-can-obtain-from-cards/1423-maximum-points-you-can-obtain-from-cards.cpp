class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        vector<int> pre(k+1, 0);
        vector<int> suf(k+1, 0);
        
        pre[1] = cardPoints[0];
        suf[1] = cardPoints[n-1];
        
        for(int i=1; i<k; i++){
            // cout << i << " " << n-i-1 << endl;
            pre[i+1] = pre[i]+cardPoints[i];
            suf[i+1] = suf[i]+cardPoints[n-i-1];
            // cout << pre[i] << " " << suf[k-i-1] << endl;
        }
        
//         for(int i=0; i<=k; i++){
//             cout << pre[i] << " ";
//         }
//         cout << endl;
        
//         for(int i=0; i<=k; i++){
//             cout << suf[i] << " ";
//         }
//         cout << endl;
        
        int maxAns = INT_MIN;
        
        for(int i=0; i<=k; i++){
            maxAns = max(maxAns, pre[i]+suf[k-i]);
        }
        
        return maxAns;
        
    }
};