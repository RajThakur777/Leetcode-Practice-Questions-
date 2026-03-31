class Solution {
public:

    int solve(int idx , int prev_idx , vector<int> &nums , int k , vector<vector<vector<int>>> &dp) {
        if(idx == nums.size()) {
            return 0;
        }

        if(dp[idx][prev_idx+1][k] != -1) {
            return dp[idx][prev_idx+1][k];
        }

        int not_pick = solve(idx+1 , prev_idx , nums , k , dp);

        int pick = 0;
        if((prev_idx == -1) || (nums[prev_idx] == nums[idx])) {
            pick = 1 + solve(idx+1 , idx , nums , k , dp);
        }
        else if((prev_idx != -1) && (nums[prev_idx] != nums[idx])) {
            if(k > 0) {
                pick = 1 + solve(idx+1 , idx , nums , k-1 , dp);
            }
        }

        return dp[idx][prev_idx+1][k] = max(pick , not_pick);
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));

        return solve(0 , -1 , nums , k , dp);   
    }
};