class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int num , int n , int x , vector<vector<int>> &dp) {
        if(n == 0) return 1;

        if(n < 0) return 0;

        int val = pow(num , x);

        if(val > n) return 0;

        if(dp[num][n] != -1) return dp[num][n];

        int pick = solve(num+1 , n - val , x , dp) % mod;

        int not_pick = solve(num+1 , n , x , dp) % mod;

        return dp[num][n] = (pick + not_pick) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

        return solve(1 , n , x , dp);
    }
};