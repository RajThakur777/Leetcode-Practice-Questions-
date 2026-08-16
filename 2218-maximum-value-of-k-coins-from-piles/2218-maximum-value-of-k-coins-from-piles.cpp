class Solution {
public:
    int n;


    int dp[1001][2001];

    int solve(int idx , vector<vector<int>> &piles , int k) {
        if(idx >= n) {
            if(k < 0) {
                return -1e9;
            }

            return 0;
        }

        if(k < 0) {
            return -1e9;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int ans = solve(idx+1 , piles , k);

        int sz = piles[idx].size();

        vector<int> prefix(sz);
        prefix[0] = piles[idx][0];

        for(int i=1; i<sz; i++) {
            prefix[i] = prefix[i-1] + piles[idx][i];
        }

        for(int j=0; j<sz; j++) {
            ans = max(ans , prefix[j] + solve(idx+1 , piles , k-(j+1)));
        }

        return dp[idx][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , piles , k);
    }
}; 