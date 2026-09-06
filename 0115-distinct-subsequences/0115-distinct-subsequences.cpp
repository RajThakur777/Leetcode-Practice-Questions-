class Solution {
public:
    int m;
    int n;

    int dp[1001][1001];

    int solve(int i , int j , string s , string t) {
        if(j == n) {
            return 1;
        }

        if(i >= m) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i+1 , j+1 , s , t) + solve(i+1 , j , s , t);
        }
        else {
            return dp[i][j] = solve(i+1 , j , s , t);
        }
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , s , t);
    }
};