class Solution {
public:
    int m;
    int n;

    int dp[71][5001];

    int solve(int i , vector<vector<int>> &mat , int target , int sum) {
        if(i == m) {
            return abs(target - sum);
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
            ans = min(ans , solve(i+1 , mat , target , sum + mat[i][j]));
        }

        return dp[i][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = INT_MAX;

        for(int j=0; j<n; j++) {
            ans = min(ans , solve(1 , mat , target , mat[0][j]));
        }

        return ans;
    }
};