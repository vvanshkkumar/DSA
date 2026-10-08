class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
         vector<int> distance(n+1,INT_MAX);
         distance[k] = 0;
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         pq.push({0,k});

         vector<vector<pair<int,int>>> list(n+1);

         for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];

            list[u].push_back({v,times[i][2]});
         }


         while(!pq.empty()){

            auto [dist, node] = pq.top(); pq.pop();

            if(dist!=distance[node]) continue;

            for(auto [neigh, time] : list[node]){

                if(dist + time < distance[neigh]){
                    pq.push({(dist+time), neigh});
                    distance[neigh] = dist+time;
                }
            }
         }

        int maxTime = 0;

        for(int i = 1; i <= n; i++){

            if(distance[i] == INT_MAX)
                return -1;

            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};