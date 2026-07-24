class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt_0 = 0;

        int ans = 0;

        int i = 0;

        for(int j=0; j<n; j++) {
            cnt_0 += (nums[j] == 0);

            while(cnt_0 > k) {
                cnt_0 -= (nums[i] == 0);
                i++;
            }

            ans = max(ans , (j - i + 1));
        }

        return ans;
    }
};