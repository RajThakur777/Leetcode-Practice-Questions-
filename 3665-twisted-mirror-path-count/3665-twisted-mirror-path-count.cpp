class Solution {
public:
    int m;
    int n;

    const int mod = 1e9 + 7;

    int dp[501][501][3];

    int solve(int i , int j , vector<vector<int>> &grid , int last) {
        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(i >= m || j >= n) {
            return 0;
        }

        if(dp[i][j][last] != -1) {
            return dp[i][j][last];
        }

        int right = 0;
        int down = 0;

        if(grid[i][j] == 0) {
            right = solve(i , j+1 , grid , 1);
            down = solve(i+1 , j , grid , 0);
        }
        else {
            if(last == 1) {
                down = solve(i+1 , j , grid , 0);
            }
            else {
                right = solve(i , j+1 , grid , 1);
            }
        }

        return dp[i][j][last] = (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , grid , 0);
    }
};