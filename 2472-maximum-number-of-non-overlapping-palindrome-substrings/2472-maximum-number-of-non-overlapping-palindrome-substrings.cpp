class Solution {
public:
    int n;

    int dp1[2001];

    int dp2[2001][2001];

    bool isPalindrome(int i , int j , string &s) {
        if(i >= j) {
            return true;
        }

        if(dp2[i][j] != -1) {
            return dp2[i][j];
        }

        if(s[i] != s[j]) {
            return dp2[i][j] = false;
        }

        return dp2[i][j] = isPalindrome(i+1 , j-1 , s);
    }

    int solve(int idx , string &s , int k) {
        if(idx >= n) {
            return 0;
        }

        if(dp1[idx] != -1) {
            return dp1[idx];
        }

        int ans = 0;

        for(int i=idx; i<n; i++) {
            if((i - idx + 1) >= k && isPalindrome(idx , i , s)) {
                ans = max(ans , 1 + solve(i+1 , s , k));
            }
            else {
                ans = max(ans , solve(i+1 , s , k));
            }
        }

        return dp1[idx] = ans;
    }

    int maxPalindromes(string s, int k) {
        n = s.size();

        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));

        return solve(0 , s , k);
    }
};