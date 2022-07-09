class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int st_time = intervals[0][0];
        int end_time = intervals[0][1];
        
        int n = intervals.size();
        
        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= end_time){
                end_time = max(end_time, intervals[i][1]);
            }
            else{
                ans.push_back({st_time, end_time});
                st_time = intervals[i][0];
                end_time = intervals[i][1];
            }
        }
        
        ans.push_back({st_time, end_time});
        
        return ans;
    }
};