class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(31 , 0);

        for(int i=0; i<=30; i++) {
            for(int j=0; j<n; j++) {
                if((nums[j] & (1 << i)) > 0) {
                    cnt[i]++;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<31; i++) {
            if(cnt[i] == 0) {
                ans++;
            }
        }

        if(ans == 31) {
            return 0;
        }

        bool f = false;

        for(int i=0; i<31; i++) {
            if(cnt[i] % 2 != 0) {
                f = true;
                break;
            }
        }

        return (f == true ? n : n-1);
    }
};