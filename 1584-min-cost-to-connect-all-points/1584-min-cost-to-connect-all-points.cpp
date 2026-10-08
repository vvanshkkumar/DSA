class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
         vector<int> visited(points.size(),0);

         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

         pq.push({0,0});
         int minDist = 0;

         while(!pq.empty()){

            auto [dist, p] = pq.top(); pq.pop();
              if(visited[p])
        continue;
            visited[p] = 1;
            minDist += dist;

            for(int i=0;i<points.size();i++){
                
                if(visited[i]==0){
                    int edgeDist = abs(points[p][0]-points[i][0]) + abs(points[p][1]-points[i][1]);
                    pq.push({edgeDist,i});
                }
            }
         }
         return minDist;
    }
};