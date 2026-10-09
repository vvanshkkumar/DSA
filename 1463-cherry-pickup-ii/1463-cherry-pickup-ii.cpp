class Solution {
public:
    
    int find(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2){

         if(row <0 || row>=grid.size() || col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()) {
            return 0;
         }
         if(row==grid.size()+1) return 0;

         if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        
        int cherry=0;
        
        int y[] = {-1,-1,-1,0,0,0,1,1,1};
        int x[] = {-1,0,1,-1,0,1,-1,0,1};

        for(int i=0;i<9;i++){

            int robot1 = col1 + x[i];
            int robot2 = col2 + y[i];

            cherry = max(cherry, find(grid, dp, row+1, robot1, robot2));
        }

         if(col1 == col2) cherry += grid[row][col1];
         else cherry = cherry + grid[row][col1] + grid[row][col2];

         return dp[row][col1][col2] = cherry;
         
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>>dp (grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(),-1)));

        return find(grid, dp, 0, 0, grid[0].size()-1);
    }
};