class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int , int>> q;

        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i , j});
                }
                else if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        int time = 0;

        while(!q.empty()) {
            int sz = q.size();

            bool f = false;

            for(int i=0; i<sz; i++) {
                auto it = q.front();
                q.pop();

                int i1 = it.first;
                int j1 = it.second;

                for(auto dir : directions) {
                    int i_ = i1 + dir[0];
                    int j_ = j1 + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                        grid[i_][j_] = 2;
                        cnt--;
                        q.push({i_ , j_});
                        f = true;
                    }
                }
            }
            if(f) {
                time++;
            }
        }

        if(cnt != 0) return -1;

        return time;
    }
};