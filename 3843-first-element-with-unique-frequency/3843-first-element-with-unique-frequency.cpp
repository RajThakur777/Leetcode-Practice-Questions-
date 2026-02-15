class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp1;
        for(int i=0; i<n; i++) {
            mpp1[nums[i]]++;
        }

        map<int , int> mpp2;
        for(auto it : mpp1) {
            mpp2[it.second]++;
        }

        for(int i=0; i<n; i++) {
            int ele = nums[i];
            int freq = mpp1[ele];

            if(mpp2[freq] == 1) {
                return ele;
            }
        }
        return -1;
    }
};