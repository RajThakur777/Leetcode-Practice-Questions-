class Solution {
public:
    int n;

    const int mod = 1e9 + 7;

    int dp[1001][1001];

    bool isPrime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7);
    }

    int solve(int idx , string &s , int k , int minLength) {
        if(idx == n) {
            if(k == 0) {
                return 1;
            }
            return 0;
        }

        if(k < 0) {
            return 0;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int ans = 0;

        for(int i=idx; i<n; i++) {
            if(i - idx + 1 >= minLength && (isPrime(s[idx] - '0')) && (!isPrime(s[i] - '0'))) {
                ans = (ans + solve(i+1 , s , k-1 , minLength)) % mod;
            }
        }

        return dp[idx][k] = (ans % mod);
    }

    int beautifulPartitions(string s, int k, int minLength) {
        n = s.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , s , k , minLength);

        ans %= mod;

        return ans;
    }
};