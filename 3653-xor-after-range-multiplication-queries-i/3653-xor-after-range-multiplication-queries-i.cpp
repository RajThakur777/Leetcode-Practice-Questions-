class Solution {
public:
    const int mod = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) { 
        int n = queries.size();

        for(int i=0; i<n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while(idx <= r && idx < nums.size()) {
                nums[idx] = (((nums[idx]) * 1LL * (v)) % (mod));
                idx += k;
            }
        }

        int xor_val = 0;
        for(int i=0; i<nums.size(); i++) {
            xor_val = (xor_val ^ nums[i]);
        }
        return xor_val;
    }
};