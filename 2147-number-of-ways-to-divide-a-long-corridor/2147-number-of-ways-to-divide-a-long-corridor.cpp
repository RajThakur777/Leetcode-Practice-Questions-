//Recursion+Memoization:
class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int idx , string &corridor , int cnt , vector<vector<int>> &dp) {
        if(cnt > 2) return 0;
        
        if(idx == corridor.size()) {
            return (cnt == 2) ? 1 : 0;
        }

        if(dp[idx][cnt] != -1) {
            return dp[idx][cnt];
        }

        if(corridor[idx] == 'S') {
            cnt++;
        }

        if(cnt == 2) {
            int pick = solve(idx+1 , corridor , 0 , dp);
            int not_pick = solve(idx+1 , corridor , cnt , dp);

            return dp[idx][cnt] = (1LL*pick + 1LL*not_pick) % mod;
        }
        int ans = solve(idx+1 , corridor , cnt , dp) % mod;

        return dp[idx][cnt] = (ans % mod);
    }

    int numberOfWays(string corridor) {  
        int n = corridor.size();

        vector<vector<int>> dp(n+1 , vector<int>(4 , -1));

        return solve(0 , corridor , 0 , dp); 
    }
};