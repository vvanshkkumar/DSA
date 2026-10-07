class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(),INT_MAX));
        queue<tuple<int,int,int>> q;


        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
              if(mat[i][j]==0){
                 q.push({i,j,0});
                 dist[i][j] = 0;
              }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y,currDist] = q.front(); q.pop();

                int a[] = {1,-1,0,0};
                int b[] = {0,0,1,-1};

                for(int k=0;k<4;k++){

                    int i = x + a[k];
                    int j = y + b[k];

                    if(i>=0 && i<mat.size() && j>=0 && j<mat[0].size()){
                     
                     if(dist[i][j]==INT_MAX){
                          dist[i][j] = currDist + 1;
                          q.push({i,j,dist[i][j]});      
                     }
                     
                    }
                }
            }
        }
        return dist;
    }
};