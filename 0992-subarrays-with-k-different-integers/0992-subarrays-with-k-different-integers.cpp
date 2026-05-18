class Solution {
public:

    int cnt_subarrays(vector<int> &nums , int k) {
        int cnt = 0;
        
        map<int , int> mpp;

        int i = 0;
        for(int j=0; j<nums.size(); j++) {
            mpp[nums[j]]++;

            while(mpp.size() > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        return cnt_subarrays(nums , k) - cnt_subarrays(nums , k-1);
    }
};