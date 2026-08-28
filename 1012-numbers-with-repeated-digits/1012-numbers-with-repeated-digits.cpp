class Solution {
public:
    int dp[11][2][(1 << 11)];

    int solve(int idx , int tight , int mask , string &str) {
        if(idx >= str.size()) {
            return 1;
        }

        if(dp[idx][tight][mask] != -1) {
            return dp[idx][tight][mask];
        }

        int limit = (tight == 1 ? str[idx] - '0' : 9);

        int ans = 0;

        for(int i=0; i<=limit; i++) {
            if(mask == 0  && i == 0) {
                ans += solve(idx+1 , tight && (i == limit) , mask , str);
            }
            else {
                if((mask & (1 << i)) > 0) {
                    continue;
                }

                ans += solve(idx+1 , tight && (i == limit) , (mask | (1 << i)) , str);
            }
        }

        return dp[idx][tight][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        memset(dp , -1 , sizeof(dp));

        string str = to_string(n);

        int ans = solve(0 , 1 , 0 , str) - 1;

        return n - ans;
    }
};