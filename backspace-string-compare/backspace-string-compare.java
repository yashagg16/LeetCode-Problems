class Solution {
    public boolean backspaceCompare(String s, String t) {
        String x = "";
        String y = "";
        
        char[] s_arr = s.toCharArray();
        char[] t_arr = t.toCharArray();
        
        int n = s_arr.length;
        int m = t_arr.length;
        
        for(int i=0; i<n; i++){
            if(s_arr[i] != '#'){
                x += s_arr[i];
            }
            else{
                if(x.length() == 0){
                    continue;
                }
                x= x.substring(0, x.length()-1);
            }
        }
        
        for(int i=0; i<m; i++){
            if(t_arr[i] != '#'){
                y += t_arr[i];
            }
            else{
                if(y.length() == 0){
                    continue;
                }
                y = y.substring(0, y.length()-1);
            }
        }
        
        if(x.equals(y)) return true;
        
        return false;
    }
}