class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> stock;
        map<int, int> need;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            stock[nums[i]] ++;
        }
        
        for(int i=0; i<n; i++){
            int num = nums[i];
            
            if(stock[num] == 0){
                // cout << "out of stock " << num << endl;
                continue;
            }
            
            if(need.find(num) != need.end() && need[num] != 0){
                // cout << "This element is needed " << num << endl;
                need[num]--;
                need[num+1]++;
                stock[num]--;
                continue;
            }
            
            if(need.find(num) == need.end() || need[num] == 0){
                // cout << "Creating a new seq " << num << endl;
                if(stock[num+1]==0 || stock[num+2] ==0){
                    // cout << "could not find " << num+1 << " " << num+2 << endl;
                    // cout << "stock count is " << stock[num+1] << " " << stock[num+2] << endl;
                    return false;
                }
                
                // cout << "Forming the seq " << stock[num] << " " << stock[num+1] << " " << stock[num+2] << endl;
                stock[num]--;
                stock[num+1]--;
                stock[num+2]--;
                need[num+3]++;
            }
            
        }
        return true;
    }
        
};