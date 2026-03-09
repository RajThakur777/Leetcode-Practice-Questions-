class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[201][201][2];

    int solve(int zero , int one , int limit , int prev) {
        if(zero == 0 && one == 0) {
            return 1;
        }

        if(dp[zero][one][prev] != -1) {
            return dp[zero][one][prev];
        }

        int p1 = 0;
        if(prev == 0) {
            for(int i=1; i<=min(zero , limit); i++) {
                p1 = (p1 + solve(zero-i , one , limit , 1)) % mod;
            }
        }
        else {
            for(int i=1; i<=min(one , limit); i++) {
                p1 = (p1 + solve(zero , one-i , limit , 0)) % mod;
            }
        }
        return dp[zero][one][prev] = (p1);
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp , -1 , sizeof(dp));

        int a1 = solve(zero , one , limit , 0) % mod;
        int a2 = solve(zero , one , limit , 1) % mod;

        return (a1 + a2) % mod;
    }
};