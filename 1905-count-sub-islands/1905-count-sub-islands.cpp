class Solution {
public:

    void find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited2, int i, int j, bool& isValid){

          visited2[i][j] = 1;

          int x[] = {-1,1,0,0};
          int y[] = {0,0,-1,1};

          for(int k=0;k<4;k++){

            int m = i + x[k];
            int n = j + y[k];

            if(m<grid2.size() && n<grid2[m].size() && m>=0 && n>=0 && visited2[m][n]==0){
                if(grid1[m][n]==1 && grid2[m][n]==1) find(grid1, grid2, visited2, m , n, isValid);
                else if(grid1[m][n]==0 && grid2[m][n]==1){
                    isValid = false;
                    find(grid1, grid2, visited2, m , n, isValid);
                }
            }
             
          }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        vector<vector<int>> visited2(grid2.size(), vector<int>(grid2[0].size(),0));

        int count = 0;
        

        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){

                bool isValid = true;

                if(visited2[i][j]==0 && grid2[i][j]==1 && grid1[i][j]==1){
                    find(grid1, grid2, visited2, i, j, isValid);
                    if(isValid) count++;
                }
            }
        }

        return count;
        



    }
};