class Solution {
public:
    int n;

    bool isPalindrome(string &s , int i , int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int dp[2001];

    int solve(int idx , string &s) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 1e9;

        for(int i=idx; i<n; i++) {
            if(isPalindrome(s , idx , i)) {
                ans = min(ans , 1 + solve(i+1 , s));
            }
        }

        return dp[idx] = ans;
    }

    int minCut(string s) {
        n = s.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , s) - 1;    
    }
};