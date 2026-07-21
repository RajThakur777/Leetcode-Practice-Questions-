class Solution {
public:
    int n;
    int dp[30001][3];

    int solve(int idx , int buy , vector<int> &prices) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        int ans = INT_MIN;

        if(buy == 0) {
            ans = max(-prices[idx] + solve(idx+1 , 1 , prices) , solve(idx+1 , 0 , prices));
        }
        else {
            ans = max(prices[idx] + solve(idx+1 , 0 , prices) , solve(idx+1 , 1 , prices));
        }

        return dp[idx][buy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , prices);
    }
};