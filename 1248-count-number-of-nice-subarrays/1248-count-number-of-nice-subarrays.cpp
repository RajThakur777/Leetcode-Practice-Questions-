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
            sum += (nums[j] % 2 != 0);

            while(sum > x) {
                sum -= (nums[i] % 2 != 0);
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k-1);
    }
};