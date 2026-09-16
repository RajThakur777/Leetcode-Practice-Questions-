class Solution {
public:
    const int mod = 1e9 + 7;

    int dp[1001][1001];

    int solve(int idx , int n , int k) {
        if(k == 0) {
            return 1;
        }

        if(idx >= n) {
            if(k == 0) {
                return 1;
            }
            return 0;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int ans = 0;

        ans = (ans + solve(idx+1 , n , k)) % mod;

        for(int j=idx+1; j<n; j++) {
            ans = (ans + solve(j , n , k-1)) % mod;
        }

        return dp[idx][k] = ans;
    }

    int numberOfSets(int n, int k) {
        if(k > n-1) {
            return 0;
        }

        if(k == n-1) {
            return 1;
        }
        
        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , n , k);

        return (ans % mod);
    }
};