class Solution {
public:
    int n;

    int dp[50001];

    int solve(int i , vector<int> &stoneValue) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = -1e9;

        ans = max(ans , stoneValue[i] - solve(i+1 , stoneValue));

        if(i+1 < n) {
            ans = max(ans , stoneValue[i] + stoneValue[i+1] - solve(i+2 , stoneValue));
        }

        if(i+2 < n) {
            ans = max(ans , stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3 , stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , stoneValue);

        if(ans > 0) {
            return "Alice";
        }

        if(ans == 0) {
            return "Tie";
        }

        return "Bob";
    }
};