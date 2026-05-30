class Solution {
public:

    double solve(int idx , vector<int> &nums , int k , vector<vector<double>> &dp) {
        if(idx >= nums.size()) {
            return 0.0;
        }

        if(k == 0) {
            return INT_MIN; 
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        double sum = 0.0;
        double ans = INT_MIN;

        for(int j=idx; j<nums.size(); j++) {
            sum += nums[j];

            ans = max(ans , ((sum / (j - idx + 1) + solve(j + 1 , nums , k - 1 , dp))));
        }
        return dp[idx][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double>> dp(n+1 , vector<double>(k+1 , -1.0));

        return solve(0 , nums , k , dp);
    }
};