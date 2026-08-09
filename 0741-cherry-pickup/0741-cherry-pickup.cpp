//4D DP
class Solution {
public:
    int n;

    int dp[51][51][51][51];

    int solve(int i1 , int j1 , int i2 , int j2 , vector<vector<int>> &grid) {
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return INT_MIN;
        }

        if(i1 == n-1 && j1 == n-1) {
            return grid[i1][j1];
        }

        if(dp[i1][j1][i2][j2] != -1) {
            return dp[i1][j1][i2][j2];
        }

        int ans = 0;

        if((i1 == i2) && (j1 == j2)) {
            ans += grid[i1][j1];
        }
        else {
            ans += grid[i1][j1] + grid[i2][j2];
        }

        int op1 = solve(i1 , j1+1 , i2 , j2+1 , grid); //r r
        int op2 = solve(i1+1 , j1 , i2+1 , j2 , grid); //d d
        int op3 = solve(i1+1 , j1 , i2 , j2+1 , grid); //r d
        int op4 = solve(i1 , j1+1 , i2+1 , j2 , grid); //d r

        ans +=  max({op1 , op2 , op3 , op4});

        return dp[i1][j1][i2][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , 0 , 0 , 0 , grid);

        if(ans < 0) {
            return 0;
        }

        return ans;
    }
};