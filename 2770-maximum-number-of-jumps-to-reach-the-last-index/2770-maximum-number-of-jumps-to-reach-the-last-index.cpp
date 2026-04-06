class Solution {
public:
    int dp[1001];

    int solve(int idx , vector<int> &nums , int target) {
        if(idx >= nums.size()) {
            return -1;
        }
        
        if(idx == nums.size()-1) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = INT_MIN;
        for(int i=idx+1; i<nums.size(); i++) {
            if((abs(nums[i] - nums[idx]) <= target) && (abs(nums[i] - nums[idx]) >= -target)) {
                ans = max(ans , 1 + solve(i , nums , target));
            }
        }
        return dp[idx] = ans;
    }
   
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , nums , target);

        if(ans < 0) {
            return -1;
        }
        return ans;
    }
};