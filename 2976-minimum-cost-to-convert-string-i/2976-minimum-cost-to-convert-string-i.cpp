class Solution {
public:
    void dijiktra(char root , vector<int> &dist , unordered_map<char , vector<pair<char , int>>> &mpp) {
        priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>> pq;

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

        vector<vector<int>> dist(26 , vector<int>(26 , INT_MAX));
        for(int i=0; i<26; i++) {
            dijiktra((i + 'a') , dist[i] , mpp);
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++) {
            if(source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == INT_MAX) return -1;

            ans += dist[u][v];
        }
        return ans;
    }
};