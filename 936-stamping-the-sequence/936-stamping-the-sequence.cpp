class Solution {
private : 
    int n;
    int m;
    vector<int> res;
    string Stamp;
    string Target;
    int stars;
    vector<int> vis;
    
public:
    bool isReplacable(int i){
        if(i+m > n){
            return false;   
        }
        // cout << "HERE" << endl;
        for(int j=i; j<=i+m-1; j++){
            if(Target[j] != Stamp[j-i] && Target[j] != '?'){
                return false;
            }
        }
        
        return true;
    }
    
    void Replace(int i){
        for(int j=i; j<=i+m-1; j++){
            if(Target[j] != '?'){
                Target[j] = '?';
                stars ++;
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target) {
        n = target.size();
        m = stamp.size();
        
        Stamp = stamp;
        Target = target;
        
        stars = 0;
        for(int i=0; i<n; i++){
            vis.push_back(0);
        }
        while(stars < n){
            // cout << Stamp << " " << Target << endl;
            // cout << "HERE" << endl;
            int fl = 0;
            for(int i=0; i<=n-m; i++){
                if(vis[i] == 0 && isReplacable(i)){
                    Replace(i);
                    fl = 1;
                    vis[i] = 1;
                    res.push_back(i);
                    break;
                }
            }
            // cout << stars << endl;
            if(stars == n){
                break;
            }
            if(fl == 0){
                res.clear(); 
                break;
            }
        }   
        reverse(res.begin(), res.end());
        return res;
    }
    
    
};