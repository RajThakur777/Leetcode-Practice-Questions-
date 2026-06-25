class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> left_min(n);
        left_min[0] = nums[0];

        for(int i=1; i<n; i++) {
            left_min[i] = min(left_min[i-1] , nums[i]);
        }

        vector<int> right_max(n);
        right_max[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--) {
            right_max[i] = max(right_max[i+1] , nums[i]);
        }

        for(int i=1; i<n-1; i++) {
            if(nums[i] > left_min[i-1] && nums[i] < right_max[i+1]) {
                return true;
            }
        }
        return false;
    }
};