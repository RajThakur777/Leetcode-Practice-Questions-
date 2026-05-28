class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            int need = target - ele;

            if(mpp.find(need) != mpp.end()) {
                return {i , mpp[need]};
            }
            else {
                mpp[ele] = i;
            }
        }
        return {};
    }
};