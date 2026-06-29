class Solution {
public:

    vector<vector<int>> directions = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
        vector<vector<bool>> vis(m , vector<bool>(n , false));

        deque<pair<int , int>> dq;
        dq.push_front({0 , 0});

        dist[0][0] = 0;

        while(!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();

            int i = it.first;
            int j = it.second;

            if(vis[i][j] == true) {
                continue;
            }

            vis[i][j] = true;

            for(int k=0; k<4; k++) {
                int i_ = i + directions[k][0];
                int j_ = j + directions[k][1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n) {
                    continue;
                }

                int cost = (grid[i][j] == k + 1 ? 0 : 1);

                if(!vis[i_][j_] && dist[i_][j_] > dist[i][j] + cost) {
                    dist[i_][j_] = dist[i][j] + cost;

                    if(cost == 0) {
                        dq.push_front({i_ , j_});
                    }
                    else {
                        dq.push_back({i_ , j_});
                    }
                } 
            }
        }
        return dist[m-1][n-1];
    }
};