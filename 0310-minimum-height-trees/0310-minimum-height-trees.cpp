class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(edges.size()==0) return {0};
        
        vector<int> outDeg(n, 0);
        vector<vector<int>> list(n);
        queue<int> q;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            list[u].push_back(v);
            list[v].push_back(u);
            outDeg[u]++;
            outDeg[v]++;
        }
        int nodes = n;

        for(int i=0;i<n;i++){
            if(outDeg[i]==1){

             q.push(i);
            
            }
        }

        vector<int> result;
        
        
        while(nodes>2){

            int size = q.size();
            nodes -= size;

            while(size--){

            int node = q.front(); q.pop();

            for(int neigh : list[node]){
                outDeg[neigh]--;
                if(outDeg[neigh]==1){
                    q.push(neigh);
                    
                }
              }
            }
        }

       while(!q.empty()){
        result.push_back(q.front());
        q.pop();
       }
        

        return result;
    }
};