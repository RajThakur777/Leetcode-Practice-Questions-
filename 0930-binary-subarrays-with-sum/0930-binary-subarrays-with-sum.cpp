class Solution {
public:
    
    int solve(vector<int> &nums , int x) {
        int cnt = 0;

        if(x < 0) {
            return 0;
        }

        int sum = 0;

        int i = 0;
        for(int j=0; j<nums.size(); j++) {
            sum += nums[j];

            while(sum > x) {
                sum -= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        return solve(nums , goal) - solve(nums , goal - 1);
    }
};