class Solution {
public:
    int sum = 0;

    void dfs(int node , int parent ,  unordered_map<int , vector<pair<int , int>>> &mpp) {
        for(auto [neigh , sign] : mpp[node]) {
            if(neigh != parent) {
                sum += sign;
                dfs(neigh , node , mpp);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int N = connections.size();

        unordered_map<int , vector<pair<int , int>>> mpp;
        for(int i=0; i<N; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            mpp[u].push_back({v , 1});
            mpp[v].push_back({u , 0});
        }

        dfs(0 , -1 , mpp);

        return sum;
    }
};