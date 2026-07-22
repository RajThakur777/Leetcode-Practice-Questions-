class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        map<int , int> mpp;

        mpp[0] = 1;

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];

            if(mpp.find(sum - k) != mpp.end()) {
                ans += mpp[sum-k];
            }

            mpp[sum]++;
        }

        return ans;
    }
};