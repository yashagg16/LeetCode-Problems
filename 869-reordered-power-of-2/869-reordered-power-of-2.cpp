typedef long long int ll;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        auto get_count = [&](int n){
            vector<int> res(10, 0);
            while(n){
                int rem = n%10;
                res[rem]++;
                n /= 10;
            }
            return res;
        };
        
        vector <int> cnt = get_count(n);
        for(int i=0; i<31; i++){
            vector<int> num = get_count(1 << i);
            
            if(cnt == num){
                return true;
            }
        }
        
        return false;
    }
};