class Solution {
public:
    int romanToInt(string s) {
        int i=0;
        int num=0;
        
        int n = s.size();
        
        while(i < n){
            if(s[i] == 'I'){
                if(i+1 < n && s[i+1] == 'V'){
                    num += 4;
                    i += 2;
                }
                else if(i+1 < n && s[i+1] == 'X'){
                    num += 9;
                    i += 2;
                }
                else{
                    num++;
                    i++;
                }                
            }
            else if(s[i] == 'V'){
                num += 5;
                i++;
            }
            else if(s[i] == 'X'){
                if(i+1<n && s[i+1]=='L'){
                    num+=40;
                    i+=2;
                }
                else if(i+1<n && s[i+1]=='C'){
                    num+=90;
                    i+=2;
                }
                else{
                    num+=10;
                    i++;
                }
            }
            else if(s[i] == 'L'){
                num+=50;
                i++;
            }
            else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    num+=400;
                    i+=2;
                }
                else if(i+1<n && s[i+1]=='M'){
                    num+=900;
                    i+=2;
                }
                else{
                    num+=100;
                    i++;
                }
            }
            else if(s[i] =='D'){
                num+=500;
                i++;
            }
            else{
                num+=1000;
                i++;
            }
        }
        
        return num;
    }
};