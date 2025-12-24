class Solution {
public:

    int solve(vector<int> &nums , int k) {
        int n = nums.size();

        if(k < 0) return 0;

        int ans = 0;

        int i = 0;
        int sum = 0;
        for(int j=0; j<n; j++) {
            sum += nums[j];

            while(sum > k) {
                sum -= nums[i];
                i++;
            }

            ans += ((j - i + 1));
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums , goal) - solve(nums , goal - 1);
    }
};