class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> list(n);

        for(vector<int> r : roads){
            int u = r[0];
            int v = r[1];
            int time = r[2];

            list[u].push_back({v, time});
            list[v].push_back({u, time});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        int MOD = 1000000007;

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto [neigh, time] : list[node]){

                if(d + time < dist[neigh]){
                    dist[neigh] = d + time;
                    ways[neigh] = ways[node];

                    pq.push({dist[neigh], neigh});
                }
                else if(d + time == dist[neigh]){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};