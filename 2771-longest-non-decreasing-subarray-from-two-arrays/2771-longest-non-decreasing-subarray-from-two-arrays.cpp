class Solution {
public:
    int n;

    int dp[100001][3];

    int solve(int idx , int k , vector<int> &nums1 , vector<int> &nums2) {
        if(idx == n) {
            return 0;
        }

        if(dp[idx][k+1] != -1) {
            return dp[idx][k];
        }

        int ans = 0;

        if(k == -1) {
            ans = max(ans , 1 + solve(idx+1 , 0 , nums1 , nums2));
            ans = max(ans , 1 + solve(idx+1 , 1 , nums1 , nums2));
            ans = max(ans ,  solve(idx+1 , -1 , nums1 , nums2));
        }
        else if(k == 0) {
            if(nums1[idx-1] <= nums1[idx]) {
                ans = max(ans , 1 + solve(idx+1 , 0 , nums1 , nums2));
            }

            if(nums1[idx-1] <= nums2[idx]) {
                ans = max(ans , 1 + solve(idx+1 , 1 , nums1 , nums2));
            }
        }
        else if(k == 1) {
            if(nums2[idx-1] <= nums1[idx]) {
                ans = max(ans , 1 + solve(idx+1 , 0 , nums1 , nums2));
            }

            if(nums2[idx-1] <= nums2[idx]) {
                ans = max(ans , 1 + solve(idx+1 , 1 , nums1 , nums2));
            }
        }
        return dp[idx][k+1] = ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , -1 , nums1 , nums2);
    }
};