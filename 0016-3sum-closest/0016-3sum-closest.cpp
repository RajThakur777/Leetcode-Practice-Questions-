class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int ans = INT_MAX;
        int res = 0;

        for(int j=1; j<n-1; j++) {
            int i = 0;
            int k = n-1;

            while(i < j && k > j) {
                int sum = nums[i] + nums[j] + nums[k];

                if(ans > abs(target - sum)) {
                    ans = abs(target - sum);
                    res = sum;
                }

                if(sum < target) {
                    i++;
                }
                else if(sum > target){
                    k--;
                }
                else {
                    return sum;
                }
            }
        }
        return res;
    }
};