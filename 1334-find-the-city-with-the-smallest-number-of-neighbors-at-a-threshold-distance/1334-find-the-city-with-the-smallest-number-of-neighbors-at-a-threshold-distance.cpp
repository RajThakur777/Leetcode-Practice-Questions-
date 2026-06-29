class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dist[u][v] = min(dist[u][v] , wt);
            dist[v][u] = min(dist[v][u] , wt);
        }

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        map<int , int> mpp;
        int mini = INT_MAX;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            mpp[i] = cnt;
            mini = min(mini , cnt);
        }

        int ans = 0;
        for(auto it : mpp) {
            if(it.second == mini) {
                ans = max(ans , it.first);
            }
        }

        return ans;
    }
};