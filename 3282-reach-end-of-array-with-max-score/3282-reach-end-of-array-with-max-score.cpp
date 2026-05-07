class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {   
        int n = nums.size();

        long long ans = 0;
        int prev = 0;

        for(int i=1; i<n; i++) {
            if(nums[i] > nums[prev]) {
                ans += ((i - prev) * 1LL * (nums[prev]));
                prev = i;
            }
        }
        return ans + ((n-1-prev) * 1LL * (nums[prev]));
    }
};