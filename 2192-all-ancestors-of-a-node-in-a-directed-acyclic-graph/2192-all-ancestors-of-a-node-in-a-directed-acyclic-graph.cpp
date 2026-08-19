class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> inDeg(n,0);
        vector<set<int>> ancestor(n);   // change
        vector<vector<int>> list(n);
        
        for(int i=0;i<edges.size();i++){

            int u = edges[i][0];
            int v = edges[i][1];
            list[u].push_back(v);

            inDeg[v]++;
        }

        queue<int> q;
        
        for(int i=0;i<inDeg.size();i++){
            if(inDeg[i]==0) q.push(i);
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(int neigh : list[node]){
                inDeg[neigh]--;
                if(inDeg[neigh]==0) q.push(neigh);

                ancestor[neigh].insert(node);
                ancestor[neigh].insert(
                    ancestor[node].begin(),
                    ancestor[node].end()
                );
            }
        }

        vector<vector<int>> ans(n);

        for(int i=0;i<n;i++){
            for(int x : ancestor[i])
                ans[i].push_back(x);
        }

        return ans;
    }
};