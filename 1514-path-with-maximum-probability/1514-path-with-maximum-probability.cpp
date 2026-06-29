class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {  
        vector<vector<pair<int , double>>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v , succProb[i]});
            adj[v].push_back({u , succProb[i]});
        } 

        priority_queue<pair<double , int>> pq;

        vector<double> dist(n , 0.0);
        vector<bool> vis(n , false);

        dist[start_node] = 1.0;
        pq.push({1.0 , start_node});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            double d = it.first;

            if(vis[node]) {
                continue;
            }

            vis[node] = true;

            for(auto t : adj[node]) {
                int neigh = t.first;
                double p = t.second;

                if(!vis[neigh] && dist[neigh] < (p * dist[node])) {
                    dist[neigh] = (p * dist[node]);
                    pq.push({dist[neigh] , neigh});
                }
            }
        }

        if(dist[end_node] == 0.0) {
            return 0;
        }

        return dist[end_node];
    }
};