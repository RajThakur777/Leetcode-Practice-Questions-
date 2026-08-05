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

    int dp[2001][5];

    bool f = false;

    bool solve(int idx , string &s , int k) {
        if(k == 0) {
            if(isPalindrome(s , idx , n-1)) {
                return true;
            }
            return false;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        for(int i=idx; i<n-1; i++) {
            if(isPalindrome(s , idx , i)) {
                if(solve(i + 1 , s , k - 1)) {
                    return true;
                }
            }
        }

        return dp[idx][k] = false;
    }


    bool checkPartitioning(string s) {
        n = s.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , s , 2); 
    }
};