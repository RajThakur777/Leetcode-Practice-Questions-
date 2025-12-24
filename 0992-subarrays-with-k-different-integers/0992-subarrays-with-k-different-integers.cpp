class Solution {
public:

    int solve(vector<int> &nums , int k) {
        unordered_map<int , int> mpp;

        int i = 0;
        int ans = 0;

        for(int j=0; j<nums.size(); j++) {
            mpp[nums[j]]++;

            while(mpp.size() > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        int n = nums.size();

        return solve(nums , k) - solve(nums , k-1);  
    }
};