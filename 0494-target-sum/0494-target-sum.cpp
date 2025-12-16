class Solution {
public:

    int solve(int idx , vector<int> &nums , int target) {
        if(idx == nums.size()) {
            return (target == 0);
        }

        int plus = solve(idx+ 1 , nums , target+nums[idx]);

        int minus = solve(idx+1 , nums , target-nums[idx]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return solve(0 , nums , target);
    }
};