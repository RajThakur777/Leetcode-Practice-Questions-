class Solution {
public:
    int maxSubarrays(vector<int>& nums) { 
        int n = nums.size();

        int val = nums[0];
        for(int i=0; i<n; i++) {
            val &= nums[i];
        }

        if(val != 0) {
            return 1;
        }

        int res = 0;
        int v = nums[0];
        for(int j=0; j<n; j++) {
            v &= nums[j];

            if(j == n-1) {
                break;
            }

            if(v == 0) {
                res++;
                v = nums[j+1];
            }
        }
        if(v == 0) {
            res++;
        }
        return res;
    }
};