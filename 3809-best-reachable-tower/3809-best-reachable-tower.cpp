class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();

        priority_queue<pair<int , pair<int , int>>>pq;
        for(int i=0; i<n; i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int dist = abs(x - center[0]) + abs(y - center[1]);

            if(dist <= radius) {
                pq.push({q , {x , y}});
            }
        }

        if(pq.empty()) return {-1 , -1};

        int ans = pq.top().first;
        
        vector<vector<int>> res;
        
        while(!pq.empty()) {
            int q = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(q == ans) {
                res.push_back({x , y});
            }
        }

        int x = res[0][0];
        int y = res[0][1];

        for(int i=0; i<res.size(); i++) {
            int x1 = res[i][0];
            int y1 = res[i][1];
            
            if((x1 < x) || (y1 < y)) {
                x = x1;
                y = y1;
            }
        }
        return {x , y};
    }
};