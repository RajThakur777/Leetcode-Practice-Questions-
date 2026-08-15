class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<=30; i++) {
            for(int j=0; j<n; j++) {
                if((nums[j] & (1 << i)) > 0) {
                    mpp[i]++;
                }
            }
        }

        if(mpp.size() == 0) {
            return 0;
        }

        for(auto it : mpp) {
            if(it.second % 2 != 0) {
                return n;
            }
        }

        return n-1;
    }
};