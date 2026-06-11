class Solution {
   
   private boolean dfs(int[][] graph, ArrayList<Integer> visited, ArrayList<Integer> color, int i, int col) {
           
           if(visited.get(i) == 1 && color.get(i)==col) return false;

           if(visited.get(i) == 1 && color.get(i)!=col) return true;

           visited.set(i,1);

           color.set(i, col==1?0:1);

           for(int neigh : graph[i]) {

            if(!dfs(graph, visited, color, neigh, color.get(i))) return false;
             
           } 
           return true;
   }
    public boolean isBipartite(int[][] graph) {

        int n = graph.length;
        
        ArrayList<Integer> visited = new ArrayList<>(Collections.nCopies(n,0));

        ArrayList<Integer> color = new ArrayList<>(Collections.nCopies(n,-1));


        for(int i=0;i<n;i++){
  
           if(visited.get(i) == 0) {
            if(!dfs(graph, visited, color, i, 0)) return false;
           }
        }

        return true;
    }
}