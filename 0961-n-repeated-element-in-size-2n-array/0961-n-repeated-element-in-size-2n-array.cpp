class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        int freq = (len) / 2;

        unordered_map<int , int> mpp;
        for(int i=0; i<len; i++) {
            mpp[nums[i]]++;
        }

        int ans = 0;

        for(auto it : mpp) {
            if(it.second == freq) {
                ans = it.first;
            }
        }
        return ans;
    }
};