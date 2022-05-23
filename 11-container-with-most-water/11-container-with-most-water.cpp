#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i=0;
        int j=n-1;
        int maxArea = 0;
        while(i < j){
            int area = (j-i)* min(height[j],height[i]);
            maxArea = max(maxArea, area);
            // cout << i << " " << height[i] << " " << j << " " << height[j] << " " << area << endl;
            if(height[j] > height[i]) i++;
            else j--;
        }
        
        return maxArea;
    }
};