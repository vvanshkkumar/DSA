class Solution {
public:
    
    void dfs(vector<vector<int>>& list, vector<int>& tin, vector<int>& low, int node, vector<vector<int>>& cc, int& timer, int parent){

          tin[node] = low[node] = ++timer;          
     
          for(int neigh : list[node]){

              if(neigh == parent) continue;
              
              if(tin[neigh]!=-1){
                low[node] = min(low[node], tin[neigh]);
            
              } else {
              
              dfs(list, tin, low, neigh, cc, timer, node);
    
              
              if(low[neigh] < tin[node]) low[node] = min(low[node], low[neigh]);
              
              else if(low[neigh] > tin[node]){
                cc.push_back({neigh, node});
              }
              }
           }
        }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);

        vector<vector<int>> list(n);

        for(int i=0;i<connections.size();i++){

            int u = connections[i][0];
            int v = connections[i][1];

            list[u].push_back(v);
            list[v].push_back(u);
        }
        vector<vector<int>> cc;
        int timer = 0;

        dfs(list, tin, low, 0, cc, timer, -1);

        return cc;
    }
};