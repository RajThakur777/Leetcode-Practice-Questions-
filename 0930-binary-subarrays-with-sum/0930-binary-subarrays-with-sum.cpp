class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {   
        int n = nums.size();

        unordered_map<int , int> mpp;

        mpp[0] = 1;
        int sum = 0;

        int cnt = 0;

        for(int i=0; i<n; i++) {
            sum += nums[i];

            if(mpp.find(sum - goal) != mpp.end()) {
                cnt += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};