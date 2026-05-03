class Solution {
public:
    #define ll long long 

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<ll> closest_x(n);
        closest_x[0] = 1;
        closest_x[n-1] = n-2;

        for(int i=1; i<n-1; i++) {
            ll d1 = abs(nums[i] - nums[i-1]);
            ll d2 = abs(nums[i] - nums[i+1]);

            if(d1 <= d2) {
                closest_x[i] = i-1;
            }
            else {
                closest_x[i] = i+1;
            }
        }

        vector<ll> left_right(n , 0);
        for(int i=0; i<n-1; i++) {
            if(closest_x[i] == (i+1)) {
                left_right[i+1] = 1;
            }
            else {
                left_right[i+1] = abs(nums[i] - nums[i+1]);
            }
        }

        vector<ll> right_left(n , 0);
        for(int i=n-1; i>0; i--) {
            if(closest_x[i] == (i-1)) {
                right_left[i-1] = 1;
            }
            else {
                right_left[i-1] = abs(nums[i] - nums[i-1]);
            }
        }

        vector<ll> prefix_left(n);
        prefix_left[0] = left_right[0];
        for(int i=1; i<n; i++) {
            prefix_left[i] = prefix_left[i-1] + left_right[i];
        }

        vector<ll> suffix_right(n);
        suffix_right[n-1] = right_left[n-1];
        for(int i=n-2; i>=0; i--) {
            suffix_right[i] = suffix_right[i+1] + right_left[i];
        }

        int sz = queries.size();

        vector<int> ans(sz);

        for(int i=0; i<queries.size(); i++) {
            ll l = queries[i][0];
            ll r = queries[i][1];

            if(l <= r) {
                ans[i] = prefix_left[r] - prefix_left[l];
            }
            else {
                ans[i] = suffix_right[r] - suffix_right[l];
            }
        }
        return ans;
    }
};