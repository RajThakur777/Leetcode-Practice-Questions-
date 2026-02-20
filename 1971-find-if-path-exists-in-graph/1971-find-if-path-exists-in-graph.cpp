class Solution {
public:

    void dfs(int node , vector<int> &visited , unordered_map<int , vector<int>> &mpp) {
        visited[node] = 1;

        for(auto it : mpp[node]) {
            if(visited[it] == 0) {
                dfs(it , visited , mpp);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {   
        vector<int> visited(n , 0);

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        dfs(source , visited , mpp);

        for(int i=0; i<n; i++) {
            if(visited[source] == 1 && visited[destination] == 1) return true;
        }
        return false;
    }
};