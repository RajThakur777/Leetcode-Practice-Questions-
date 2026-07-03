class Solution {
public:
    #define ll long long 

    int n;

    bool check(ll mid , vector<vector<pair<ll , ll>>> &adj , ll k) {
        vector<ll> dist(n , LLONG_MAX);
        vector<bool> vis(n , false);

        priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;
        pq.push({0 , 0});
        dist[0] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ll d = it.first;
            ll node = it.second;

            if(vis[node]) {
                continue;
            }

            vis[node] = true;

            for(auto t : adj[node]) {
                ll neigh = t.first;
                ll dt = t.second;

                if(dist[node] + dt <= k && dt >= mid && !vis[neigh] && dist[neigh] > dist[node] + dt) {
                    dist[neigh] = dist[node] + dt;
                    pq.push({dist[neigh] , neigh});
                }
            }
        }
        return (dist[n-1] != LLONG_MAX);
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int sz = edges.size();

        n = online.size();

        vector<vector<pair<ll , ll>>> adj(n);
        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];

            if(online[u] == false || online[v] == false) {
                continue;
            }

            adj[u].push_back({v , c});
        }

        ll low = 0;
        ll high = 1e9;

        ll ans = -1;

        while(low <= high) {
            ll mid = (low + high) / 2;

            if(check(mid , adj , k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};