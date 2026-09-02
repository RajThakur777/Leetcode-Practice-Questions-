class Solution {
public:

    long long dp[16][2][2][11];

    long long solve(int idx , int tight , int lz , int prev_d , string &s , int k) {
        if(idx == s.size()) {
            return (lz == 0);
        }

        if(dp[idx][tight][lz][prev_d + 1] != -1) { 
            return dp[idx][tight][lz][prev_d + 1];
        }

        int limit = (tight) ? (s[idx] - '0') : 9;

        long long ans = 0;

        for(int dig=0; dig<=limit; dig++) {
            if(!lz && abs(prev_d - dig) > k) {
                continue;
            }

            int nextTight = (tight && (dig == limit));

            int nextLz = (lz && (dig == 0));

            int nextDig = (nextLz ? -1 : dig);

            ans += solve(idx+1 , nextTight , nextLz , nextDig , s , k);
        }

        return dp[idx][tight][lz][prev_d + 1] = ans;
    }

    long long count(string &s , int k) {
       memset(dp , -1 , sizeof(dp));

       return solve(0 , 1 , 1 , -1 , s , k);
    }

    long long goodIntegers(long long l, long long r, int k) {
        string s1 = to_string(l-1);
        string s2 = to_string(r);

        return count(s2 , k) - count(s1 , k);
    }
};