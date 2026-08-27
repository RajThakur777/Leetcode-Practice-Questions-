class Solution {
public:
    int n;

    const int mod = 1e9 + 7;

    int dp[41][(1 << 10)];

    int solve(map<int , vector<int>> &mpp , int hat , int mask) {
        if(mask == (1 << n) - 1) {
            return 1;
        }

        if(hat > 40) {
            return 0;
        }

        if(dp[hat][mask] != -1) {
            return dp[hat][mask];
        }

        int not_pick = solve(mpp , hat+1 , mask);

        int pick = 0;

        for(auto it : mpp[hat]) {
            if((mask & (1 << it)) == 0) {
                pick = (pick + solve(mpp , hat+1 , (mask | (1 << it)))) % mod;
            }
        }

        return  dp[hat][mask] = (pick + not_pick) % mod;
    }

    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();

        memset(dp , -1 , sizeof(dp));

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            vector<int> v = hats[i];

            for(int j=0; j<v.size(); j++) {
                mpp[v[j]].push_back(i);
            }
        }

        int ans = solve(mpp , 1 , 0);

        ans %= mod;

        return ans;
    }
};