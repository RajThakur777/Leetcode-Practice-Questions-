class Solution {
public:
    int dp[1001][1001];

    int solve(int idx , vector<int> &nums , int target) {
        if(target == 0) {
            return 0;
        }

        if(target < 0 || idx >= nums.size()) {
            return INT_MIN;
        }

        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int take = 1 + solve(idx+1 , nums , target - nums[idx]);
        int not_take = solve(idx+1 , nums , target);

        return dp[idx][target] = max(take , not_take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));
        
        int ans = solve(0 , nums , target);

        if(ans < 0) {
            return -1;
        }
        return ans;
    }
};