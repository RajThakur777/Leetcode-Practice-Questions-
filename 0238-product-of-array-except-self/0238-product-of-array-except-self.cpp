class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = (prefix[i-1] * 1LL * nums[i]);
        }

        vector<long long> suffix(n);
        suffix[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--) {
            suffix[i] = (suffix[i+1] * 1LL * nums[i]);
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[i] = (suffix[i+1]);
            }
            else if(i == n-1) {
                ans[i] = prefix[i-1];
            }
            else {
                int val = (prefix[i-1] * 1LL * suffix[i+1]);
                ans[i] = val;
            }
        }
        return ans;
    }
};