class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;


        unordered_map<long long , long long> mpp;

        int i = 0;
        long long pairs = 0;
        for(int j=0; j<n; j++) {
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k) {
                ans += (n - j);
                mpp[nums[i]]--;
                pairs -= mpp[nums[i]];
                i++;
            }
        }
        return ans;
    }
};