class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int sz = queries.size();

        vector<int> ans(sz);

        int sum = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }

        for(int i=0; i<sz; i++) {
            int idx = queries[i][1];
            int val = queries[i][0];

            int prev_val = nums[idx];

            if(prev_val % 2 == 0) {
                sum -= prev_val;
            }

            int new_val = nums[idx] + val;

            nums[idx] = new_val;

            if(new_val % 2 == 0) {
                sum += new_val;
            }

            ans[i] = sum;
        }
        return ans;
    }
};