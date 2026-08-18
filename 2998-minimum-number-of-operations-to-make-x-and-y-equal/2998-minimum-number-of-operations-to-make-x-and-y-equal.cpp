class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        if(x == y) return 0;

        queue<int> q;
        q.push(x);

        unordered_map<int, bool> visited;
        visited[x] = true;

        int count = 0;

        while(!q.empty()) {

            int size = q.size();
            count++;

            while(size--) {

                int node = q.front();
                q.pop();

                if(node % 11 == 0) {

                    if(node / 11 == y) return count;

                    if(!visited.count(node / 11)) {
                        visited[node / 11] = true;
                        q.push(node / 11);
                    }
                }

                if(node % 5 == 0) {

                    if(node / 5 == y) return count;

                    if(!visited.count(node / 5)) {
                        visited[node / 5] = true;
                        q.push(node / 5);
                    }
                }

                if(node + 1 == y) return count;

                if(!visited.count(node + 1)) {
                    visited[node + 1] = true;
                    q.push(node + 1);
                }

                if(node > 0) {

                    if(node - 1 == y) return count;

                    if(!visited.count(node - 1)) {
                        visited[node - 1] = true;
                        q.push(node - 1);
                    }
                }
            }
        }

        return 0;
    }
};