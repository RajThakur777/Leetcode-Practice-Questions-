class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();

        long long ans = 0;

        int i = 0;
        long long sum = 0;

        map<int , int> mpp;

        for(int j=0; j<n; j++) {
            sum += nums[j];
            mpp[nums[j]]++;

            if((j - i + 1) > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
            }

            if((j - i + 1) == k) {
                if(mpp.size() >= m) {
                    ans = max(ans , sum);
                }
            }
        }
        return ans;
    }
};