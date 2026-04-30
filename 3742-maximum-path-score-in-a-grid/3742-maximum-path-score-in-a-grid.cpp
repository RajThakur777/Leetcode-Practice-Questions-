class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , vector<vector<int>> &grid , int k , vector<vector<vector<int>>> &dp) {
        if(i == m-1 && j == n-1) {
            if(grid[i][j] != 0) {
                return (k >= 1 ? grid[i][j] : INT_MIN);
            }
            else {
                return (k < 0 ? INT_MIN : grid[i][j]);
            }
        }

        if(k < 0) {
            return INT_MIN;
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int right = grid[i][j] + solve(i , j+1 , grid , k-(grid[i][j] != 0 ? 1 : 0) , dp);

        int down = grid[i][j] + solve(i+1 , j , grid , k-(grid[i][j] != 0 ? 1 : 0) , dp);

        return dp[i][j][k] = max(right , down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));

        int ans = solve(0 , 0 , grid , k , dp);

        if(ans < 0) {
            return -1;
        }
        return ans;
    }
};