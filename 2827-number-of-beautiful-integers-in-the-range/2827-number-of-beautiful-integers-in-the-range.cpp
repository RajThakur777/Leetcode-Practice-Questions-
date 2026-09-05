class Solution {
public:
    int dp[10][2][2][10][10][20];

    int solve(int idx , int tight , int lz , int even , int odd , int rem , int k , string &s) {
        if(idx == s.size()) {
            return (lz == 0 && (even == odd) && (rem == 0));
        }

        if(dp[idx][tight][lz][even][odd][rem] != -1) {
            return dp[idx][tight][lz][even][odd][rem];
        }

        int limit = (tight ? s[idx] - '0' : 9);

        int ans = 0;

        for(int dig=0; dig<=limit; dig++) {
            int nextTight = (tight && (limit == dig));
            
            if(lz && dig == 0) {
                ans += solve(idx+1 , nextTight , 1 , even , odd , 0 , k , s);
            }
            else if(dig % 2 == 0) {
                ans += solve(idx+1 , nextTight , 0 , even+1 , odd , (rem * 10 + dig) % k , k , s);
            }
            else {
                ans += solve(idx+1 , nextTight , 0 , even , odd+1 , (rem * 10 + dig) % k , k , s);
            }
        }

        return dp[idx][tight][lz][even][odd][rem] = ans;
    }

    int count(string s , int k) {
        memset(dp , -1 , sizeof(dp));
        
        return solve(0 , 1 , 1 , 0 , 0 , 0 , k , s);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(low-1);
        string s2 = to_string(high);

        return count(s2 , k) - count(s1 , k);
    }
};