class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        map<int , int> mpp;

        int ans = 0;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            ans = max(ans , (j - i + 1));
        }

        return ans;
    }
};