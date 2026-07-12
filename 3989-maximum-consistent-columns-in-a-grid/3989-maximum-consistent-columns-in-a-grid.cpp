class Solution {
public:
    int m;
    int n;

    int dp[251][251];

    int solve(int col , int prev_col , vector<vector<int>> &grid , int limit) {
        if(col >= grid[0].size()) {
            return 0;
        }

        if(dp[col][prev_col+1] != -1) {
            return dp[col][prev_col+1];
        }

        int not_pick = solve(col+1 , prev_col , grid , limit);

        int pick = 0;

        if(prev_col == -1) {
            pick = 1 + solve(col+1 , col , grid , limit);
        }
        else {
            bool f = true;

            for(int i=0; i<m; i++) {
                if(abs(grid[i][col] - grid[i][prev_col]) > limit) {
                    f = false;
                    break;
                }
            }

            if(f) {
                pick = 1 + solve(col+1 , col , grid , limit);
            }
        }

        return dp[col][prev_col+1] = max(pick , not_pick);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = 0;

        for(int j=0; j<n; j++) {
            ans = max(ans , solve(j , -1 , grid , limit));
        }

        return ans;
    }
};