class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int val = nums[i];
            int v = -1;
            for(int j=1; j<=999; j++) {
                if((j | (j + 1)) == val) {
                    v = j;
                    break;
                }
            }
            ans[i] = v;
        }
        return ans;
    }
};