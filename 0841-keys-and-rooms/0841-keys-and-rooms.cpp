class Solution {
public:

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<int> &visited) {
        visited[node] = 1;

        for(auto it : mpp[node]) {
            if(visited[it] == 0) {
                dfs(it , mpp , visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            for(auto it : rooms[i]) {
                mpp[i].push_back(it);
            }
        }      

        vector<int> visited(n , 0);

        dfs(0 , mpp , visited);

        for(int i=0; i<n; i++) {
            if(visited[i] == 0) return false;
        }
        return true;
    }
};