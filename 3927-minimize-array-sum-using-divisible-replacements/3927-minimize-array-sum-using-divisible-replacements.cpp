class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        map<long long  , long long> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        sort(nums.begin() , nums.end());

        long long limit = nums[n-1];
        
        for(int i=0; i<n; i++) {
            long long ele = nums[i];
            long long cnt = 0;
            long long val = ele;

            while((ele <= limit) && !mpp.empty()) {
                if(mpp.find(ele) != mpp.end()) {
                    cnt += mpp[ele];
                    mpp.erase(ele);
                }
                ele += val;
            }

            ans += ((cnt) * 1LL * (val));
        }

        if(!mpp.empty()) {
            for(auto it : mpp) {
                ans += ((it.second) * 1LL * (it.first));
            }
        }
        return ans;
    }
};