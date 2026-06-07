class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int , int> mpp;

        vector<int> res;

        for(int i=0; i<n; i++) {
            int x = nums[i];

            int need = target - x;

            if(mpp.find(need) != mpp.end()) {
                res.push_back(i);
                res.push_back(mpp[need]);
                break;
            }
            else {
                mpp[x] = i;
            }
        }
        return res;
    }
};