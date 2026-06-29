class Solution {
public:
    #define ll long long 

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int , int>>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];

            adj[u].push_back({v , time});
        }

        vector<vector<bool>> vis(n , vector<bool>(power+1 , false));
        vector<vector<ll>> dist(n , vector<ll>(power+1 , LLONG_MAX));

        priority_queue<pair<ll , pair<ll , ll>> , vector<pair<ll , pair<ll , ll>>> , greater<pair<ll , pair<ll , ll>>>>pq;

        pq.push({0 , {source , power}});
        dist[source][power] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ll d = it.first;
            ll node = it.second.first;
            ll p = it.second.second;

            if(vis[node][p] == true) {
                continue;
            }

            vis[node][p] = true;

            for(auto t : adj[node]) {
                ll neigh = t.first;
                ll dt = t.second;

                if(p >= cost[node]) {
                    if(!vis[neigh][p - cost[node]] && dist[neigh][p - cost[node]] > dist[node][p] + dt) {
                        dist[neigh][p - cost[node]] = dist[node][p] + dt;
                        pq.push({dist[node][p] + dt , {neigh , p - cost[node]}});
                    }
                }
            }
        }

        vector<ll> ans;

        ll val = LLONG_MAX;

        for(int i=0; i<=power; i++) {
            val = min(val , dist[target][i]);
        }

        if(val == LLONG_MAX) {
            return {-1 , -1};
        }

        ans.push_back(val);

        ll p = LLONG_MIN;

        for(int i=0; i<=power; i++) {
            if(dist[target][i] == val) {
                p = max(p , (ll)i);
            }
        }

        ans.push_back(p);

        return ans;
    }
};