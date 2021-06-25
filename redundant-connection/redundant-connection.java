class Solution {
    public int findParent(int a, int[] parent){
        if(parent[a] != a){
            parent[a] = findParent(parent[a], parent);
        }
        return parent[a];
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n+1];
        int[] rank = new int[n+1];
        
        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        int[] ans = new int[2];
        for(int i=0; i<n; i++){
            int ch = edges[i][0];
            int pa = edges[i][1];
            int p_ch = findParent(ch, parent);
            int p_pa = findParent(pa, parent);
            
            if(p_pa == p_ch){
                ans[0] = ch;
                ans[1] = pa;
            }
            else{
                if(rank[p_ch] <= rank [p_pa]){
                    parent[p_ch] = p_pa;
                }
                else{
                    parent[p_pa] = p_ch;
                }
            }
        }
        
        return ans;
    }
}