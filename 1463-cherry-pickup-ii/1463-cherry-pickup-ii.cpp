//4D DP
class Solution {
public:
    int m;
    int n;

    int dp[75][75][75];

    int solve(int i1 , int j1  , int j2 , vector<vector<int>> &grid) {
        if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return INT_MIN;
        }

        if(i1 == m-1) {
            if(j1 == j2) {
                return grid[i1][j1];
            }

            return grid[i1][j1] + grid[i1][j2];
        }

        if(dp[i1][j1][j2] != -1) {
            return dp[i1][j1][j2];
        }

        int ans = 0;

        if((j1 == j2)) {
            ans = grid[i1][j1];
        }
        else {
            ans = grid[i1][j1] + grid[i1][j2];
        }

        int op1 = solve(i1+1 , j1-1 , j2-1 , grid);
        int op2 = solve(i1+1 , j1-1 , j2 , grid);
        int op3 = solve(i1+1 , j1-1 , j2+1 , grid);
        int op4 = solve(i1+1 , j1 , j2-1 , grid);
        int op5 = solve(i1+1 , j1 , j2 , grid);
        int op6 = solve(i1+1 , j1 , j2+1 , grid);
        int op7 = solve(i1+1 , j1+1 , j2-1 , grid);
        int op8 = solve(i1+1 , j1+1 , j2 , grid);
        int op9 = solve(i1+1 , j1+1 , j2+1 , grid);

        ans += max({op1 , op2 , op3 , op4 , op5 , op6 , op7 , op8 , op9});

        return dp[i1][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , 0 , n-1 , grid);

        if(ans < 0) {
            return 0;
        }

        return ans;
    }
};