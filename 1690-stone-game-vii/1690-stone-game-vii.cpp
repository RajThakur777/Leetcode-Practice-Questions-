class Solution {
public:
    int n;

    int dp[1001][1001];

    int solve(int i , int j , vector<int> &stones , int total) {
        if(i > j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = -1e9;

        ans = max(ans , (total - stones[i]) - solve(i+1 , j , stones , total - stones[i]));

        ans = max(ans , (total - stones[j]) - solve(i , j-1 , stones , total - stones[j]));

        return dp[i][j] = ans;
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();

        memset(dp , -1 , sizeof(dp));

        int total = 0;
        for(auto x : stones) {
            total += x;
        }

        return solve(0 , n-1 , stones , total);
    }
};