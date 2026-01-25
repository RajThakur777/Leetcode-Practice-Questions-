class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int i = 0;
        int ans = INT_MAX;

        for(int j=0; j<n; j++) {
            while(j - i + 1 > k) {
                i++;
            }

            if((j - i + 1) == k) {
                ans = min(ans , nums[j] - nums[i]);
            }
        }
        return ans;
    }
};