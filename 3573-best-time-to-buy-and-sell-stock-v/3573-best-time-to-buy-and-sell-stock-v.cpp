class Solution {
public:

    long long solve(int idx , int state , vector<int> &prices , int k , vector<vector<vector<long long>>> &dp) {
        if(k < 0) return -1e9;

        if(idx == prices.size()) {
            if(state == 0) {
                return 0;
            }
            return -1e9;
        }

        if(dp[idx][state][k] != -1) {
            return dp[idx][state][k];
        }

        long long normal = -1e9;
        long long st = -1e9;
        long long skip = solve(idx+1 , state , prices , k , dp);

        if(state == 0) {
            normal = -prices[idx] + solve(idx+1 , 1, prices , k , dp);
            st = prices[idx] + solve(idx+1 , 2 , prices , k , dp);
        }
        else if(state == 1) {
            normal = prices[idx] + solve(idx+1 , 0 , prices , k-1 , dp);
        }
        else if(state == 2) {
            st = -prices[idx] + solve(idx+1 , 0 , prices , k-1 , dp);
        }

        return dp[idx][state][k] = max(skip , max(st , normal));
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<vector<long long>>> dp(n+1 , vector<vector<long long>>(4 , vector<long long>(k+1 , -1)));

        return solve(0 , 0 , prices , k , dp);
    }
};