class Solution {
public:

    int dp[101][101][101];

    int solve(int idx , vector<int> &nums , int op1 , int op2 , int k) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx][op1][op2] != -1) {
            return dp[idx][op1][op2];
        }

        int ans = INT_MAX;

        // option5: skip
        ans = nums[idx] + solve(idx+1 , nums , op1 , op2 , k);

        // option1
        if(op1 > 0) {
            ans = min(ans , ((nums[idx] + 1) / 2) + solve(idx+1 , nums , op1-1 , op2 , k));
        }

        // option2
        if(op2 > 0 && k <= nums[idx]) {
            ans = min(ans , ((nums[idx] - k) + solve(idx+1 , nums , op1 , op2-1 , k)));
        }

        // option3 (1 then 2)
        if(op1 > 0 && op2 > 0 && k <= ((nums[idx] + 1) / 2)) {
            int val = (nums[idx] + 1) / 2;
            ans = min(ans , (val - k) + solve(idx+1 , nums , op1-1 , op2-1 , k));
        }

        // option4 (2 then 1)
        if(op1 > 0 && op2 > 0 && k <= nums[idx]) {
            int val = nums[idx] - k;
            ans = min(ans , ((val + 1) / 2) + solve(idx+1 , nums , op1-1 , op2-1 , k));
        }

        return dp[idx][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        return solve(0 , nums , op1 , op2 , k);
    }
};