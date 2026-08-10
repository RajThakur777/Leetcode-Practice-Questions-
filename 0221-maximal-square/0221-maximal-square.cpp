class Solution {
public:
    int m;
    int n;

    int dp[301][301];

    int solve(int i , int j , vector<vector<char>> &matrix) {
        if(i >= m || j >= n) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(matrix[i][j] == '0') {
            return dp[i][j] = 0;
        }

        return dp[i][j] = 1 + min({solve(i+1 , j , matrix) , solve(i+1 , j+1 , matrix) , solve(i , j+1 , matrix)});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1') {
                    int r = solve(i , j , matrix);

                    ans = max(ans , (r * r));
                }
            }
        }
        return ans;
    }
};