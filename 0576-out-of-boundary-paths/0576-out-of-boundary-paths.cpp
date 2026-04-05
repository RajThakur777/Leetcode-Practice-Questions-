class Solution {
public:
    const int mod = 1e9 + 7;

    int dp[51][51][51];

    int solve(int i , int j , int m , int n , int maxMove) {
        if(maxMove < 0) {
            return 0;
        }

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }

        if(dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }

        long long ans = 0;
        ans += solve(i+1  , j , m , n , maxMove-1) % mod;
        ans += solve(i , j+1 , m , n , maxMove-1) % mod;
        ans += solve(i-1 , j , m , n , maxMove-1) % mod;
        ans += solve(i , j-1 , m , n , maxMove-1) % mod;

        return dp[i][j][maxMove] = (ans % mod);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                for(int k=0; k<51; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return (solve(startRow , startColumn , m , n , maxMove));
    }
};