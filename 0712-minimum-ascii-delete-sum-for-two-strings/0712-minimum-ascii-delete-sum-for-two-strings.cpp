class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp) {
        if(i == m || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = s1[i] + solve(i+1 , j+1 , s1 , s2 , dp);
        }
        else {
            return dp[i][j] = max(solve(i+1 , j , s1 , s2 , dp) , solve(i , j+1 , s1 , s2 , dp));
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        int sum1 = 0;
        for(int i=0; i<m; i++) {
            sum1 += s1[i];
        }

        int sum2 = 0;
        for(int i=0; i<n; i++) {
            sum2 += s2[i];
        }

        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

        int ans = solve(0 , 0 , s1 , s2 , dp);

        return sum1 + sum2 - (2 * ans);
    }
};