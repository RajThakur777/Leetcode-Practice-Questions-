class Solution {
public:
    int n;

    long long dp[100001][3][4];

    long long solve(int idx , int prev , string &s , int k) {
        if(idx == n) {
            return (k == 0);
        }

        if(k < 0) {
            return 0;
        }

        if(dp[idx][prev+1][k] != -1) {
            return dp[idx][prev+1][k];
        }

        long long not_pick = solve(idx+1 , prev , s , k);

        long long pick = 0;

        if((prev) != (s[idx] - '0')) {
            pick = solve(idx+1 , (s[idx] - '0') , s , k-1);
        }

        return dp[idx][prev+1][k] = (pick + not_pick);
    }

    long long numberOfWays(string s) {
        n = s.size();

        int k = 3;

        memset(dp , -1 , sizeof(dp));

        return solve(0 , -1 , s , k);
    }
};