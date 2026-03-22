class Solution {
public:
    int dp[41][16384];
    int solve(int idx , vector<int> &nums , int target) {
        if(idx == nums.size()) {
            return (target == 0) ? 0 : -1e9;
        }

        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int pick = 1 + solve(idx+1 , nums , (target ^ nums[idx]));

        int not_pick = solve(idx+1 , nums , target);

        return dp[idx][target] = max(pick , not_pick);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        memset(dp,  -1 , sizeof(dp));

        int len = solve(0 , nums , target);

        if(len < 0) {
            return -1;
        }
        if(len == n) {
            return 0;
        }
        return n - len;
    }
};