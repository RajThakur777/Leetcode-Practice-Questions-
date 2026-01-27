class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int N = edges.size();

        unordered_map<int , vector<pair<int , int>>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            mpp[u].push_back({v , wt});
            mpp[v].push_back({u , 2 * wt});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        vector<int> dist(n , INT_MAX);
        pq.push({0 , 0});

        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();

            for(auto it : mpp[node]) {
                int neigh = it.first;
                int dt = it.second;

                if((d + dt) < dist[neigh]) {
                    dist[neigh] = d + dt;
                    pq.push({d + dt , neigh});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};