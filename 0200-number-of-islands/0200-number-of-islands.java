class Solution {
    
    private void find(char[][] grid, ArrayList<ArrayList<Integer>> visited, int i, int j) {
       
        if ((i<0 || i>=grid.length) || (j<0 || j>=grid[0].length)){
             return;
        }

        if(visited.get(i).get(j)==1 || grid[i][j] == '0') return;

        visited.get(i).set(j,1);

        find(grid, visited, i+1, j);
        find(grid, visited, i-1, j);
        find(grid, visited, i, j-1);
        find(grid, visited, i, j+1);

        return;
    }

    public int numIslands(char[][] grid) {
        
        int n = grid.length;
        int m = grid[0].length;

        ArrayList<ArrayList<Integer>> visited = new ArrayList<>();

        for(int i=0;i<n;i++){

            visited.add(new ArrayList<Integer>(Collections.nCopies(m,0)));
        }

        int island = 0;

        for(int i=0;i<visited.size();i++){

            for(int j=0;j<visited.get(i).size();j++){

            if(visited.get(i).get(j)==0 && grid[i][j] == '1') {
                
                find(grid, visited, i, j);
                island++;
            }
        }
        }

        return island;

    }
}