class Solution {
public:
    int n;

    int dp[101][101][101];

    bool solve(int idx , int open , int close , string &s) {
        if(idx == n) {
            return (open == close);
        }

        if(close > open) {
            return false;
        }

        if(dp[idx][open][close] != -1) {
            return dp[idx][open][close];
        }

        if(s[idx] == '*') {
            return dp[idx][open][close] = solve(idx+1 , open+1 , close , s) || solve(idx+1 , open , close+1 , s) || solve(idx+1 , open , close , s);
        }
        
        if(s[idx] == '(') {
            return dp[idx][open][close] = solve(idx+1 , open+1 , close , s);
        }
        else {
            return dp[idx][open][close] = solve(idx+1 , open , close+1 , s);
        }
    }

    bool checkValidString(string s) {
        n = s.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , 0 , s);
    }
};