class Solution {
public:
    int n;

    int dp1[2001];

    int dp2[2001][2001];

    bool isPalindrome(string &s , int i , int j) {
        if(i >= j) {
            return true;
        }

        if(dp2[i][j] != -1) {
            return dp2[i][j];
        }

        return dp2[i][j] = (isPalindrome(s , i+1 , j-1) && (s[i] == s[j]));
    }

    int solve(int idx , string &s , int k) {
        if(dp1[idx] != -1) {
            return dp1[idx];
        }

        int ans = 0;

        for(int i=idx; i<n; i++) {
            if((i - idx + 1) >= k && isPalindrome(s , idx , i)) {
                ans = max(ans , 1 + solve(i + 1 , s , k));
            }
            else {
                ans = max(ans , solve(i + 1 , s , k));
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