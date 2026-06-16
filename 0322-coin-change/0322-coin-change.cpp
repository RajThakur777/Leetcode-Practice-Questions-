class Solution {
public:
    int dp[13][10001];

    long long solve(int idx , vector<int> &coins , int amount) {
        if(idx >= coins.size()) {
            return (amount == 0 ? 0 : 1e9);
        }

        if(amount < 0) {
            return 1e9;
        }

        if(dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        long long take = 1 + solve(idx , coins , amount - coins[idx]);

        long long not_take = solve(idx+1 , coins , amount);

        return dp[idx][amount] = min(take , not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        memset(dp , -1 , sizeof(dp));

        long long ans = solve(0 , coins , amount);

        if(ans == 1e9) {
            return -1;
        }

        return ans;
    }
};