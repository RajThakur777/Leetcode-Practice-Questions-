class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        map<int , vector<int>> mpp;

        int prev = nums[0];
        int idx = 0;

        for(int i=1; i<n; i++) {
            if(nums[i] == prev) {
                prev = nums[i];
                idx = i;
            }
            else {
                mpp[prev].push_back(idx);
                prev = nums[i];
                idx = i;
            }
        }

        mpp[prev].push_back(idx);

        int ans = 0;

        for(auto it : mpp) {
            if(it.second.size() == 1) {
                ans++;
            }
        }

        return ans;
    }
};