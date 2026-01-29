class Solution {
public:
    void dijiktra(char root , vector<int> &dist , priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>> &pq , unordered_map<char , vector<pair<char , int>>> &mpp) {
        pq.push({0 , root});
        dist[root - 'a'] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            char node = pq.top().second;

            pq.pop();

            for(auto it : mpp[node]) {
                int dt = it.second;
                char neigh = it.first;

                if(d + dt < dist[neigh - 'a']) {
                    dist[neigh - 'a'] = d + dt;
                    pq.push({d + dt , neigh});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char , vector<pair<char , int>>> mpp;

        for(int i=0; i<original.size(); i++) {
            char u = original[i];
            char v = changed[i];
            int ct = cost[i];

            mpp[u].push_back({v , ct});
        }
        
        priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>> pq;

        long long ans = 0;
        for(int i=0; i<source.size(); i++) {
            if(source[i] == target[i]) continue;

            vector<int> dist(26 , INT_MAX);

            dijiktra(source[i] , dist , pq , mpp);

            if(dist[target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            else {
                ans += dist[target[i] - 'a'];
            }
        }
        return ans;
    }
};