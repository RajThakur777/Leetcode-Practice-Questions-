class Solution {
public:
    int m;
    int n;

    const int mod = 1e9 + 7;

    int dp[301][301][17];

    int solve(int i , int j , vector<vector<int>>&grid , int k) {
        if(i == m - 1 && j == n - 1) {
            return ((k ^ grid[i][j]) == 0);
        }

        if(i >= m || j >= n) {
            return 0;
        }

        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int right = solve(i , j + 1 , grid , (k ^ grid[i][j]));
        int down = solve(i + 1 , j , grid , (k ^ grid[i][j]));

        return dp[i][j][k] = (right + down) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , grid , k);
    }
};