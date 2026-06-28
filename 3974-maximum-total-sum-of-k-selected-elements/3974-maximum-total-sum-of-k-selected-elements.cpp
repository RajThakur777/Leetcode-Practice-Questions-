class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int cnt = k;

        long long sum = 0;

        for(int i=n-1; i>=0; i--) {
            if(cnt == 0) {
                break;
            }
            else {
                if(mul == 0) {
                    sum += nums[i];
                    cnt--;
                }
                else {
                    long long val = (nums[i] * 1LL * mul);
                    sum += val;
                    cnt--;
                    mul--;
                }
            }
        }
        return sum;
    }
};