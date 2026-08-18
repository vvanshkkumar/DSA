class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> list(n);
        vector<vector<int>> checkList(n);

        for(int i=0;i<connections.size();i++){

            int u = connections[i][0];
            int v = connections[i][1];

            list[u].push_back(v);
            checkList[v].push_back(u);
        }

        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        int count = 0;

        while(!q.empty()){

            int node = q.front();
            visited[node] = 1;
            q.pop();

                for(int neigh : list[node]){
                   if(visited[neigh]==0){
                    count++;
                   q.push(neigh);
                   }
                }
                for(int neigh : checkList[node]){
                    if(visited[neigh]==0){
                     q.push(neigh);
                    }
                }  
        }
       return count;
    }
};