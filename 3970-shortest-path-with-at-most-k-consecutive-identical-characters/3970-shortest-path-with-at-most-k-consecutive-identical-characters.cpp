class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int sz = edges.size();

        vector<vector<pair<int , int>>> adj(n);
        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v , wt});
        }

        vector<vector<int>> dist(n , vector<int>(k+1 , INT_MAX));
        vector<vector<bool>> vis(n , vector<bool>(k+1 , false));

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;

        pq.push({0 , {0 , 1}});
        dist[0][1] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second.first;
            int cnt = it.second.second;

            if(vis[node][cnt] == true) {
                continue;
            }

            vis[node][cnt] = true;

            for(auto t : adj[node]) {
                int neigh = t.first;
                int dt = t.second;

                if(labels[neigh] == labels[node]) {
                    if(cnt + 1 <= k) {
                        if(!vis[neigh][cnt + 1] && dist[neigh][cnt + 1] > dist[node][cnt] + dt) {
                            dist[neigh][cnt + 1] = dist[node][cnt] + dt;
                            pq.push({dist[neigh][cnt + 1] , {neigh , cnt + 1}});
                        }
                    }
                }
                else {
                    if(!vis[neigh][1] && dist[neigh][1] > dist[node][cnt] + dt) {
                        dist[neigh][1] = dist[node][cnt] + dt;
                        pq.push({dist[neigh][1] , {neigh , 1}});
                    }
                }
            }
        }

        int ans = INT_MAX;

        for(int i=0; i<=k; i++) {
            ans = min(ans , dist[n-1][i]);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};