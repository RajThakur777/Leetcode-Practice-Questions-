class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin() , nums.end());

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<long long> ans(m);

        for(int i=0; i<m; i++) {
            int val = queries[i];

            int it = lower_bound(nums.begin() , nums.end() , val) - nums.begin();

            if(it == n) {
                long long v1 = (queries[i] * 1LL * n);
                long long v2 = prefix[n-1];

                ans[i] = (v1 - v2);
            }
            else {
                long long left = (it * 1LL * queries[i]) - (it > 0 ? prefix[it-1] : 0);
                long long right = 0;

                if(nums[it] == val) {
                    right = (prefix[n-1] - (prefix[it])) - ((n - it - 1) * 1LL * queries[i]);
                }
                else {
                    right = (prefix[n-1] - (it > 0 ? prefix[it-1] : 0)) - ((n - it) * 1LL * queries[i]);
                }

                ans[i] = (left + right);
            }
        }
        return ans;
    }
};