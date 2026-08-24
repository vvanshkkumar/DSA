class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        int a[] = {-1,1,0,0,1,-1,-1,1};
        int b[] = {0,0,-1,1,1,-1,1,-1};

        vector<vector<int>> visited(n,vector<int> (n,0));
        visited[0][0] = 1;
        int count = 0;

        while(!q.empty()){

            int size = q.size();
            count++;


            while(size--){
                auto [i,j] = q.front();
                q.pop();
                
                 if(i==n-1 && j==n-1) return count;

                for(int k=0;k<8;k++){

                    int x = i + a[k];
                    int y = j + b[k];

                    if(x<n && y<n && x>=0 && y>=0 && visited[x][y]==0 && grid[x][y]==0){
                        visited[x][y] = 1;
                
                        q.push({x,y});
                    }
                }
            }
            
        }
        return -1;
    }
};