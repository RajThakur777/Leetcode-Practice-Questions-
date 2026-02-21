class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int sz = times.size();

        unordered_map<int , vector<pair<int , int>>> mpp;
        for(int i=0; i<sz; i++) {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            mpp[u].push_back({v , time});
        }

        vector<int> dist(n+1 , INT_MAX);
        dist[0] = 0;
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int d = it.first;

            for(auto it : mpp[node]) {
                int neigh = it.first;
                int wt = it.second;

                if(d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh] , neigh});
                }
            }
        }

        int maxi = *max_element(dist.begin() , dist.end());

        return (maxi == INT_MAX) ? -1 : maxi; 
    }
};