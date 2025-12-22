class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        int i = 0;
        int cnt = 0;
        for(int j=0; j<n; j++) {
            cnt += (nums[j] == 0);

            while(cnt > k) {
                cnt -= (nums[i] == 0);
                i++;
            }

            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};