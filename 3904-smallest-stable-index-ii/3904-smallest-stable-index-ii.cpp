class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
             int n = nums.size();

        vector<int> prefix_maxi(n);
        prefix_maxi[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix_maxi[i] = max(prefix_maxi[i-1] , nums[i]);
        }

        vector<int> suffix_mini(n);
        suffix_mini[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--) {
            suffix_mini[i] = min(suffix_mini[i+1] , nums[i]);
        }

        for(int i=0; i<n; i++) {
            if(prefix_maxi[i] - suffix_mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};