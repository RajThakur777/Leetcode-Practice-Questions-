class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , vector<int> &nums1 , vector<int> &nums2 , vector<vector<int>> &dp) {
        if(i == m || j == n) {
            return -100000000;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int val = nums1[i] * nums2[j];

        int op1 = solve(i+1 , j+1 , nums1 , nums2 , dp) + val;
        int op2 = solve(i , j+1 , nums1 , nums2 , dp);
        int op3 = solve(i+1 , j , nums1 , nums2 , dp);

        return dp[i][j] = max({val , op1 , op2 , op3});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {  
        m = nums1.size();
        n = nums2.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

        return solve(0 , 0 , nums1 , nums2 , dp);
    }
};