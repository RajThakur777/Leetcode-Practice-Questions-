class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        int idx = -1;

        for(int i=n-1; i>=0; i--) {
            mpp[nums[i]]++;

            if(mpp[nums[i]] >= 2) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        return (idx / 3) + 1;
    }
};