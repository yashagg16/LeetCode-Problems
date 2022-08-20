class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;    
        
        int currFuel = startFuel;
        int prevLoc = 0;
        
        int n = stations.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout << "current " << prevLoc << " " << currFuel << endl;
            
            int loc = stations[i][0];
            int fuel  = stations[i][1];
            
            // cout << "fuel station " << loc << " " << fuel << endl;
            currFuel -= (loc-prevLoc);
            
            while(!pq.empty() && currFuel < 0){
                currFuel += pq.top();
                pq.pop();
                ans++;
            }
            
            if(currFuel < 0){
                return -1;
            }
            
            pq.push(fuel);
            prevLoc = loc;
        }
        
        currFuel -= (target-prevLoc);
        while(!pq.empty() && currFuel<0){
            currFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        if(currFuel < 0){
            return -1;
        }
        
        return ans;
        
    }
};