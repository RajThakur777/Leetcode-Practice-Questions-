class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));

        dist[0][0] = 0;

        deque<pair<int , int>> dq;

        dq.push_front({0 , 0});

        while(!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();

            int i_ = it.first;
            int j_ = it.second;

            for(auto dir : directions) {
                int i1 = i_ + dir[0];
                int j1 = j_ + dir[1];

                if(i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && dist[i1][j1] == INT_MAX) {
                    if(grid[i1][j1] == 1) {
                        dist[i1][j1] = dist[i_][j_] + 1;
                        dq.push_back({i1 , j1});
                    }
                    else {
                        dist[i1][j1] = dist[i_][j_];
                        dq.push_front({i1 , j1});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};