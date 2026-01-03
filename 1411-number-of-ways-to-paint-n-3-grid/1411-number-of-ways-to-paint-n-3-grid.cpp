class Solution {
public:
     
    vector<string> v =  {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    const int mod = 1e9 + 7;

    int solve(int row , int prev , int n , vector<vector<int>> &dp) {
        if(row == n) return 1;

        if(dp[row][prev] != -1) {
            return dp[row][prev];
        }

        int ans = 0;

        for(int i=0; i<12; i++) {
            if(i == prev) continue;

            string s1 = v[i];
            string s2 = v[prev];

            bool f = true;
            for(int j=0; j<3; j++) {
                if(s1[j] == s2[j]) {
                    f = false;
                    break;
                }
            }

            if(f) {
                ans = (ans + solve(row + 1 , i , n , dp)) % mod;
            }
        }
        return dp[row][prev] = ans;
    }

    int numOfWays(int n) {
        int ans = 0;

        vector<vector<int>> dp(n , vector<int>(12 , -1));

        for(int i=0; i<12; i++) {
            ans = (ans + solve(1 , i , n , dp)) % mod;
        }
        return ans;
    }
};