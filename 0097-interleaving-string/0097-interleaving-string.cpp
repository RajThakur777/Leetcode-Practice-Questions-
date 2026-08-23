class Solution {
public:
    int m;
    int n;
    int l;

    int dp[101][101][202];

    bool solve(int i , int j , int k , string &s1 , string &s2 , string &s3) {
        if(i >= m && j >= n && k >= l) {
            return true;
        }

        if(k >= l) {
            return false;
        }

        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        if((s1[i] == s3[k]) && (s2[j] == s3[k])) {
            return dp[i][j][k] = solve(i+1 , j , k+1 , s1 , s2 , s3) || solve(i , j+1 , k+1 , s1 , s2 , s3);
        }
        else {
            if(s1[i] == s3[k]) {
                return dp[i][j][k] = solve(i+1 , j , k+1 , s1 , s2 , s3);
            }
            else if(s2[j] == s3[k]){
                return dp[i][j][k] = solve(i , j+1 , k+1 , s1 , s2 , s3);
            }
            else {
                return dp[i][j][k] = false;
            }
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        l = s3.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , 0 , s1 , s2 , s3);       
    }
};