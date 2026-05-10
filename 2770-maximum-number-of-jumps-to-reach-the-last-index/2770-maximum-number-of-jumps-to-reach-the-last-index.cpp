class Solution {
public: 
    int dp[1001];

    int solve(int idx , vector<int> &nums , int target) {
        if(idx == nums.size() - 1) {
            return 0;
        }

        if(idx >= nums.size()) {
            return INT_MIN;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = INT_MIN;

        for(int j=idx+1; j<nums.size(); j++) {
            if((nums[j] - nums[idx]) >= -target && (nums[j] - nums[idx]) <= target) {
                ans = max(ans , 1 + solve(j , nums , target));
            }
        }
        return dp[idx] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , nums , target);

        if(ans < 0) {
            return -1;
        }

        return ans;
    }
};