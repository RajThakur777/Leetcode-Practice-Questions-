class Solution {
public:
    int n;

    const int mod = 1e9 + 7;

    int dp[51][1001];

    int solve(int idx , int target , vector<vector<int>> &types) {
        if(idx == n) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }

        if(target < 0) {
            return 0;
        }

        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int not_pick = solve(idx+1 , target , types);

        int pick = 0;

        int count = types[idx][0];
        int score = types[idx][1];

        for(int i=1; i<=count; i++) {
            pick = (pick + solve(idx+1 , target - ((i * 1LL * score)) , types)) % mod;
        }

        return dp[idx][target] = (pick + not_pick) % mod;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , target , types);

        ans %= mod;

        return ans;
    }
};