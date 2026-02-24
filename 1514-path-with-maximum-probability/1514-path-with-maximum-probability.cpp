class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int sz = edges.size();

        unordered_map<int , vector<pair<int , double>>> mpp;
        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            double val = succProb[i];

            mpp[u].push_back({v , val});
            mpp[v].push_back({u , val});
        }

        priority_queue<pair<double , int>> pq;
        vector<double> dist(n , 0.0);

        dist[start_node] = (1.0);

        pq.push({1.0 , start_node});

        while(!pq.empty()) {
            auto it  = pq.top();
            pq.pop();

            double v = it.first;
            int node = it.second;

            for(auto it : mpp[node]) {
                int neigh = it.first;
                double value = it.second;

                if((v * value) > dist[neigh]) {
                    dist[neigh] = (v * value);
                    pq.push({(v * value) , neigh});
                }
            }
        }
        return dist[end_node] == (0.0) ? 0 : dist[end_node];
    }
};