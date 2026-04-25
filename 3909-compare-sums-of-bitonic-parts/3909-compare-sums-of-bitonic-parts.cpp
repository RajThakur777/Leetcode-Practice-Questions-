class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                idx = i;
                break;
            }
        }

        long long s1 = 0;
        long long s2 = 0;

        for(int i=0; i<=idx; i++) {
            s1 += nums[i];
        }

        for(int i=idx; i<n; i++) {
            s2 += nums[i];
        }

        if(s1 > s2) {
            return 0;
        }
        else if(s2 > s1) {
            return 1;
        }
        return -1;
    }
};