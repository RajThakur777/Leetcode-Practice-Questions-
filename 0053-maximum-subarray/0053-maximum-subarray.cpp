class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int cs = 0;

        for(int i=0; i<n; i++) {
            cs += nums[i];

            ans = max(ans , cs);

            if(cs < 0) {
                cs = 0;
            }
        }

        return ans;
    }
};