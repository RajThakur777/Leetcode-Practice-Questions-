class Solution {
public:
    int m;
    int n;
    int solve(int i , int j , vector<vector<int>>& grid , int value , vector<vector<vector<int>>> &dp) {
        if(i == m-1 && j == n-1) {
            return (value ^ grid[i][j]);
        }

        if(i >= m || j >= n) {
            return INT_MAX;
        }

        if(dp[i][j][value] != -1) {
            return dp[i][j][value];
        }

        int right = solve(i , j+1 , grid , (value ^ grid[i][j]) , dp);
        int down = solve(i+1 , j , grid , (value ^ grid[i][j]) , dp);

        return dp[i][j][value] = min(right , down);
    }
    
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(1024 , -1)));
        return solve(0 , 0 , grid , 0 , dp);
    }
};