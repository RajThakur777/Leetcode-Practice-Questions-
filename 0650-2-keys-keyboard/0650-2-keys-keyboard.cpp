class Solution {
public:
    int dp[1001][1001];

    int solve(int len , int copy , int n) {
        if(len == n) {
            return 0;
        } 

        if(len > n) {
            return 1e9;
        }

        if(dp[len][copy] != -1) {
            return dp[len][copy];
        }

        int p1 = INT_MAX;
        int p2 = INT_MAX;

        if(copy == 0) {
            p1 = 2 + solve(len + 1 , 1 , n);
        }
        else {
            p1 = 2 + solve(len + len , len , n);
            p2 = 1 + solve(len + copy , copy , n);
        }
        return dp[len][copy] = min(p1 , p2);
    }

    int minSteps(int n) {
        memset(dp , -1 , sizeof(dp));

        return solve(1 , 0 , n);
    }
};