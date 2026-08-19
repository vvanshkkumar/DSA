class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        vector<vector<int>> list(colors.size());
        vector<int> inDeg(colors.size());

        queue<int> q; // {index, color value}

        for(vector<int> edge : edges){
            int a = edge[0];
            int b = edge[1];
            list[a].push_back(b);
            inDeg[b]++;
        }

        vector<vector<int>> currColor(colors.size(), vector<int>(26,0));

        for(int i=0;i<currColor.size();i++){
            currColor[i][colors[i]-'a'] = 1;
        }

        for(int i=0;i<inDeg.size();i++) if(inDeg[i]==0) q.push(i);

        while(!q.empty()){

            int node = q.front(); q.pop();

          

               for(int neigh : list[node]){

    for(int c = 0; c < 26; c++)
        currColor[neigh][c] =
            max(currColor[neigh][c], currColor[node][c]);

  currColor[neigh][colors[neigh]-'a'] =
    max(currColor[neigh][colors[neigh]-'a'],
        currColor[node][colors[neigh]-'a'] + 1);

    inDeg[neigh]--;
    if(inDeg[neigh]==0)
        q.push(neigh);
}
        }


        for(int val : inDeg){
            if(val>0) return -1;
        }

        int maxCol = 0;

        for(vector<int> colors : currColor){
          
          for(int color : colors) maxCol = max(maxCol, color);
        }

         

        return maxCol;

    }
};