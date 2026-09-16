class Solution {
public:
    int m = 1e9 + 7;
    int dp[1001][1001];

    long long solve(int k, int i, int n) {
        if (k == 0) {
            return 1;
        }

        if (i == n) {
            return 0;
        }

        if (dp[k][i] != -1) {
            return dp[k][i];
        }

        long long skip = solve(k, i + 1, n);

        long long take = 0;

        for (int j = i + 1; j < n; j++) {
            take += solve(k - 1, j, n);
            take = take % m;
        }
        
        return dp[k][i] = (skip + take) % m;
    }

    int numberOfSets(int n, int k) {
        if (k > n - 1)
            return 0;

        if (k == n - 1)
            return 1;

        memset(dp, -1, sizeof(dp));

        return solve(k, 0, n);
    }
};