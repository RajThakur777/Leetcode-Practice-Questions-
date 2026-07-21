class Solution {
public:
    int n;

    int dp[10001];

    int solve(int idx , vector<int> &nums) {
        if(idx == n-1) {
            return 0;
        }

        if(idx >= n) {
            return 1e9;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 1e9;

        int val = nums[idx];

        for(int i=idx+1; i<=idx+val; i++) {
            ans = min(ans , 1 + solve(i , nums));
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , nums);
    }
};