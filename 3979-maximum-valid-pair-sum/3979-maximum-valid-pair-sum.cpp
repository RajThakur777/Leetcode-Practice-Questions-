class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        multiset<int> mt;

        int ans = 0;

        for(int i=k; i<n; i++) {
            mt.insert(nums[i-k]);

            int val = *mt.rbegin();

            ans = max(ans , nums[i] + val);
        }

        return ans;
    }
};