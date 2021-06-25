class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        int ur = 0;
        int lr = n-1;
        int lc = 0;
        int rc = m-1;
        
        while(ur <= lr && lc <= rc){
            int stx = ur;
            int sty = lc;
            int endx = lr;
            int endy = rc;
            
            while(sty < rc){
                int tmp1 = matrix[ur][sty];
                int tmp2 = matrix[stx][rc];
                int tmp3 = matrix[lr][endy];
                int tmp4 = matrix[endx][lc];
                
                matrix[ur][sty] = tmp4;
                matrix[stx][rc] = tmp1;
                matrix[lr][endy] = tmp2;
                matrix[endx][lc] = tmp3;
                sty++; stx++; endy--; endx --;
            }
            ur++;
            lr--;
            lc++;
            rc--;
        }
    }
}