class Solution {
public:
    int n;

    int dp[303][303];

    int solve(int l , int r , vector<int> &arr) {
        if(l > r) {
            return 0;
        } 

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0; 

        for(int mid=l; mid<=r; mid++) {
            ans = max(ans , ((arr[mid] * arr[l - 1] * arr[r + 1])) + solve(l , mid - 1 , arr) + solve(mid + 1 , r , arr));
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();

        memset(dp , -1 , sizeof(dp));

        vector<int> arr;
        arr.push_back(1);

        for(int i=0; i<n; i++) {
            arr.push_back(nums[i]);
        }

        arr.push_back(1);

        int sz = arr.size();

        return solve(1 , sz - 2 , arr);
    }
};