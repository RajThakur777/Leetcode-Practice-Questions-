class Solution {
public:

    int solve(int idx , vector<int> &nums , int target , vector<vector<int>> &dp) {
        if(target == 0) return 1;

        if(idx >= nums.size() || target < 0) return 0;

        if(dp[idx][target] != -1) return dp[idx][target];

        int pick = solve(0 , nums , target-nums[idx] , dp);

        int not_pick = solve(idx+1 , nums , target , dp);

        return dp[idx][target] = pick + not_pick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n+1 , vector<int>(1001 , -1));

        return solve(0 , nums , target , dp);   
    }
};