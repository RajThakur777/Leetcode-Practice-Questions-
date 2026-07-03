class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) { 
        int n = passingFees.size();

        vector<vector<pair<int , int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];

            adj[u].push_back({v , c});
            adj[v].push_back({u , c});
        }

        vector<vector<int>> dist(n , vector<int>(maxTime + 1 , INT_MAX));
        vector<vector<bool>> vis(n , vector<bool>(maxTime + 1 , false));

        priority_queue<pair<pair<int , int> , int> , vector<pair<pair<int , int> , int>> , greater<pair<pair<int , int> , int>>> pq;

        pq.push({{passingFees[0] , 0} , 0});
        dist[0][0] = passingFees[0];

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int cost = it.first.first;
            int d = it.first.second;
            int node = it.second;

            if(vis[node][d]) {
                continue;
            }

            vis[node][d] = true;

            for(auto t : adj[node]) {
                int neigh = t.first;
                int t1 = t.second;

                if(d + t1 <= maxTime && !vis[neigh][d + t1] && dist[neigh][d + t1] > dist[node][d] + passingFees[neigh]) {
                    dist[neigh][d + t1] = dist[node][d] + passingFees[neigh];
                    pq.push({{dist[neigh][d + t1] , d + t1} , neigh});
                }
            } 
        }

        int ans = INT_MAX;

        for(int i=0; i<=maxTime; i++) {
            ans = min(ans , dist[n-1][i]);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};