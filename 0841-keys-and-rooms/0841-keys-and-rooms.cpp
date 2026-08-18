class Solution {
public:
    
    void find(vector<vector<int>>& rooms, vector<int>& visited, int i){

        if(visited[i]==1) return;

        visited[i] = 1;

        for(int room : rooms[i]){

            find(rooms, visited, room);
        }

        return;
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<int> visited(rooms.size(),0);

        find(rooms, visited, 0);

        for(int val : visited) {
            if(val==0) return false;
        }

        return true;
    }
};