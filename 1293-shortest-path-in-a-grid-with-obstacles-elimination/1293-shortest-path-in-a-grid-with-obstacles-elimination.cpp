class Solution {
public:
    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dist(m , vector<vector<int>>(n , vector<int>(k+1 , INT_MAX)));

        dist[0][0][0] = 0;

        queue<pair<pair<int , int> , int>> q;

        q.push({{0 , 0} , 0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int i_ = it.first.first;
            int j_ = it.first.second;
            int val = it.second;

            if(val == k+1) {
                continue;
            } 

            for(auto dir : directions) {
                int i1 = i_ + dir[0];
                int j1 = j_ + dir[1];

                if(i1 >= 0 && i1 < m && j1 >= 0 && j1 < n) {
                    if(grid[i1][j1] == 1) {
                        if(val < k && dist[i1][j1][val + 1] == INT_MAX) {
                            dist[i1][j1][val+1] = dist[i_][j_][val] + 1;
                            q.push({{i1 , j1} , val + 1});
                        }
                    }
                    else {
                        if(dist[i1][j1][val] == INT_MAX) {
                            dist[i1][j1][val] = dist[i_][j_][val] + 1;
                            q.push({{i1 , j1} , val});
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;

        for(int k1=0; k1<=k; k1++) {
            ans = min(ans , dist[m-1][n-1][k1]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};