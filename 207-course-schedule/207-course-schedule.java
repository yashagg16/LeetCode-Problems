class Solution {
    public int dfs(ArrayList<ArrayList<Integer>> arlist, int[] visited, int i){
        visited[i] = 1;
        for(int x : arlist.get(i)){
            if(visited[x] == 1) return 1;
            else if(visited[x] == 0){
                int k = dfs(arlist, visited, x);
                if(k == 1) return 1;
            }
        }
        visited[i] = 2;
        return 0; 
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] visited = new int[numCourses];
        
        ArrayList<ArrayList<Integer>> arlist = new ArrayList<>();
        
        for(int i=0; i<numCourses; i++){
            arlist.add(new ArrayList<Integer>());
        }
        
        for(int i=0; i<prerequisites.length; i++){
            arlist.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }
        
        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                int x = dfs(arlist, visited, i);
                if(x == 1) return false;
            }
        }
        
        return true;
    }
}