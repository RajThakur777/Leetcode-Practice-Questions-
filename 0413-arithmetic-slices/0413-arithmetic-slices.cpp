class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2) {
            return 0;
        }

        vector<int> diff;
        for(int i=1; i<n; i++) {
            diff.push_back(nums[i] - nums[i-1]);
        }

        int prev = diff[0];
        int cnt = 1;

        int ans = 0;

        for(int i=1; i<diff.size(); i++) {
            if(diff[i] == prev) {
                cnt++;
            }
            else {
                ans += (((cnt) * (cnt - 1)) / 2);
                prev = diff[i];
                cnt = 1;
            }
        }

        ans += (((cnt) * (cnt - 1)) / 2);

        return ans;
    }
};