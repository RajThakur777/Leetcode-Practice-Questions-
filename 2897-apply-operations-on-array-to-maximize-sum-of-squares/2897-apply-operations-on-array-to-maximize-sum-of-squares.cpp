class Solution {
public:

    const int mod = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> cnt(31 , 0);

        for(int i=0; i<=30; i++) {
            for(auto x : nums) {
                if((x & (1 << i)) > 0) {
                    cnt[i]++;
                }
            }
        }

        int ans = 0;

        while(k--) {
            int x = 0;

            for(int i=0; i<=30; i++) {
                if(cnt[i] > 0) {
                    x |= (1 << i);
                    cnt[i]--;
                }
            }

            ans = (ans + (x * 1LL * x)) % mod;
        }

        return ans;
    }
};