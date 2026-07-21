class Solution {
public:
    int n;

    int dp[10001];

    bool solve(int idx , vector<int> &nums) {
        if(idx == n-1) {
            return true;
        }

        if(idx >= n) {
            return false;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int val = nums[idx];

        for(int i=idx+1; i<=idx+val; i++) {
            if(solve(i , nums) == true) {
                return true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , nums);
    }
};