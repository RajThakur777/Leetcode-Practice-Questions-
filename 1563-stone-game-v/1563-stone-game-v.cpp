class Solution {
public:
    int n;

    int dp[501][501];

    int solve(int i , int j , vector<int> &prefix) {
        if(i == j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = -1e9;

        for(int k=i; k<j; k++) {
            int left = prefix[k] - (i == 0 ? 0 : prefix[i-1]);
            int right = prefix[j] - prefix[k];

            if(left < right) {
                ans = max(ans , left + solve(i , k , prefix));
            }
            else if(right < left) {
                ans = max(ans , right + solve(k+1 , j , prefix));
            }
            else {
                ans = max(ans , max({left + solve(i , k , prefix) , right + solve(k+1 , j , prefix)}));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        memset(dp , -1 , sizeof(dp));

        vector<int> prefix(n);
        prefix[0] = stoneValue[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + stoneValue[i];
        }

        return solve(0 , n-1 , prefix);
    }
};