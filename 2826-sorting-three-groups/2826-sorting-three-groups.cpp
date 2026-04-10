class Solution {
public:
    int dp[101][101];

    int solve(int idx , vector<int> &nums , int prev_idx) {
        if(idx == nums.size()) {
            return 0;
        }

        if(dp[idx][prev_idx+1] != -1) {
            return dp[idx][prev_idx+1];
        }

        int not_pick = solve(idx+1 , nums , prev_idx);

        int pick = 0;
        if((prev_idx == -1) || (nums[prev_idx] <= nums[idx])) {
            pick = 1 + solve(idx+1 , nums , idx);
        }

        return dp[idx][prev_idx+1] = max(pick , not_pick);
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , nums , -1);

        return (n - ans);
    }
};