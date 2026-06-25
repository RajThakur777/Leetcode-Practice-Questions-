class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            map<int , int> mpp;
            for(int j=i; j<n; j++) {
                mpp[nums[j]]++;

                if((j - i + 1) / 2 < mpp[target]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};