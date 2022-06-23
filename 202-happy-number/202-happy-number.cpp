class Solution {
public:
    bool recur(int n, map<int, bool>& mp){
        
        if(mp.find(n) != mp.end()) return mp[n];
        
        int temp = n;
        long long int sum = 0;
        
        while(temp > 0){
            sum += ((temp%10)*(temp%10));
            temp = temp/10;
        }
        
        if(sum/10 == 0){
            if(sum == 1){
                mp[sum] = true;
                return true;
            }
        }
        mp[sum] = recur(sum, mp);
        
        return mp[sum];
    }
    bool isHappy(int n) {
        set<int> s;
        
        while(n != 1 && (s.find(n) == s.end())){
            s.insert(n);
            int temp = 0;
            while(n > 0){
                temp += (n%10)*(n%10);
                n = n/10;
            }
            n = temp;
        }
        return n==1;
        
    }
};