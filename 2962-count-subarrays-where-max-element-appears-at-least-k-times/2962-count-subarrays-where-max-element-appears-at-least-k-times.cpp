class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {   
        int n = nums.size();

        long long ans = 0;

        long long maxi = *max_element(nums.begin() , nums.end());

        unordered_map<long long  , long long> mpp;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while(mpp[maxi] >= k) {
                ans += (n - j);
                mpp[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};