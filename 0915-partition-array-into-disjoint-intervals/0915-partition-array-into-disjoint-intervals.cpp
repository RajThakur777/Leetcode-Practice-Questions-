class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        left[0] = nums[0];
        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1] , nums[i]);
        }

        vector<int> right(n);
        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = min(right[i+1] , nums[i]);
        }

        for(int i=0; i<n-1; i++) {
            if(left[i] <= right[i+1]) {
                return i+1;
            }
        }
        return -1;
    }
};