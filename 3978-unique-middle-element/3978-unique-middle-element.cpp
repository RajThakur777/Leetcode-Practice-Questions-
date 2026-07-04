class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        int val = nums[(n / 2)];

        if(mpp[val] == 1) {
            return true;
        }

        return false;
    }
};