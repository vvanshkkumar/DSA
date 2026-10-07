class Solution {
public:
    
    bool dfs(vector<vector<int>>& list, vector<int>& colors, int node, int color){

           colors[node] = color;

           for(int neigh : list[node]){
             
             if(colors[neigh]!=-1 && colors[node]==colors[neigh]) return false;
             else if(colors[neigh]==-1) {
                
                bool final = colors[node]==0?dfs(list, colors, neigh, 1):dfs(list, colors, neigh, 0);

                if(!final) return false;
             }
           }

           return true;
         
    }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> list(n+1);

        for(int i=0;i<dislikes.size();i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<int> colors(n+1,-1);

      

        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
             if(!dfs(list, colors, i, 0)) return false;
            
            }
        }

        return true;
    }
};