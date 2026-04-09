class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = n / 2;

        long long ops = 0;

        if(nums[mid] == k) return 0;

        else if(nums[mid] > k) {
            for(int i = mid; i >= 0; i--) {
                if(nums[i] > k) {
                    ops += (nums[i] - k);
                }
                else break;
            }
        }
        else {
            for(int i = mid; i < n; i++) {
                if(nums[i] < k) {
                    ops += (k - nums[i]);
                }
                else break;
            }
        }
        return ops;
    }
};