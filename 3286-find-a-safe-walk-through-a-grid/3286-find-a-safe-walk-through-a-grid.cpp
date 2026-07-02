class Solution {
public:
    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dist(m , vector<vector<int>>(n , vector<int>(health+1 , INT_MAX)));

        vector<vector<vector<bool>>> vis(m , vector<vector<bool>>(n , vector<bool>(health+1 , false)));

        deque<pair<pair<int , int> , int>> dq;

        int start = grid[0][0];

        if(start >= health)
           return false;

        dq.push_front({{0,0},start});
        dist[0][0][start] = start;

        while(!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();

            int i = it.first.first;
            int j = it.first.second;
            int h = it.second;

            if(vis[i][j][h]) {
                continue;
            }

            vis[i][j][h] = true;

            for(auto dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n) {
                    continue;
                }

                int c = grid[i_][j_] == 1 ? 1 : 0;

                if(h + c <= health-1) {
                    if(!vis[i_][j_][h + c] && dist[i_][j_][h + c] > dist[i][j][h] + c) {
                        dist[i_][j_][h + c] = dist[i][j][h] + c;

                        if(c == 0) {
                            dq.push_front({{i_ , j_} , h + c});
                        }
                        else {
                            dq.push_back({{i_ , j_} , h + c});
                        }
                    }
                }
            }
        }

        for(int i=0; i<=health-1; i++) {
            if(dist[m-1][n-1][i] != INT_MAX) {
                return true;
            }
        }

        return false;
    }
};