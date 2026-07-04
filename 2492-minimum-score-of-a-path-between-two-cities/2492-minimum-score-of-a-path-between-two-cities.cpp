class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int sz = roads.size();

        vector<vector<pair<int , int>>> adj(n+1);

        for(int i=0; i<sz; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }

        vector<int> dist(n+1 , INT_MAX);
        vector<bool> vis(n+1 , false);

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , 1});
        dist[1] = 0;

        int ans = INT_MAX;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if(vis[node]) {
                continue;
            }

            vis[node] = true;

            for(auto t : adj[node]) {
                int neigh = t.first;
                int wt = t.second;

                ans = min(ans , wt);

                if(!vis[neigh] && dist[neigh] > dist[node] + wt) {
                    dist[neigh] = dist[node] + wt;
                    pq.push({dist[neigh] , neigh});
                } 
            }
        }

        return ans;
    }
};