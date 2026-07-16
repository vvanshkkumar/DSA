class Solution {
public:
    
    int find(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){

        if(dp[i][j]!=-1) return dp[i][j];

        int x[] = {0,0,-1,1};
        int y[] = {-1,1,0,0};

        int path = 1;

        for(int k=0;k<4;k++){

            int a = i + x[k];
            int b = j + y[k];

          if(((a<matrix.size() && a>=0) && (b<matrix[0].size() && b>=0)) && matrix[a][b] > matrix[i][j])
          path = max(1 + find(matrix, dp, a, b), path);
        }

        dp[i][j] = path;

        return path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),-1));

        int paths = 0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                paths = max(find(matrix, dp, i, j), paths);
            }
        }

        return paths;
    }
};