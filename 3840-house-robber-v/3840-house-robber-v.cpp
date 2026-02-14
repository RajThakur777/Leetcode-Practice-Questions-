class Solution {
public:
    long long solve(int idx , vector<int> &nums , vector<int> &colors , vector<long long> &dp) {
        if(idx == nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long pick = LLONG_MIN;

        if(idx+1 < nums.size() && colors[idx] == colors[idx+1]) {
            pick = nums[idx] + solve(idx+2 , nums , colors , dp);
        }
        else {
            pick = nums[idx] + solve(idx+1 , nums , colors , dp);
        }

        long long not_pick = solve(idx+1 , nums , colors , dp);

        return dp[idx] = max(pick , not_pick);
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();

        vector<long long> dp(n+1 , -1);

        return solve(0 , nums , colors , dp);
    }
};