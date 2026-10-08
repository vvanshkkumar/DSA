class Solution {
public:
    
    int find(vector<int>& parent, int node){

         if(node==parent[node]) return node;

        return parent[node] = find(parent, parent[node]);
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int> parent(isConnected.size());

        for(int i=0;i<parent.size();i++) parent[i] = i;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){

                if(isConnected[i][j]==1){

               int rootI = find(parent, i);
               int rootJ = find(parent, j);

                 if(rootI != rootJ)
                   parent[rootI] = rootJ;

                }
            }
        }
         
         int count = 0;
        

        for(int i=0;i<parent.size();i++) if(parent[i]==i) count++;

        return count;
    }
};