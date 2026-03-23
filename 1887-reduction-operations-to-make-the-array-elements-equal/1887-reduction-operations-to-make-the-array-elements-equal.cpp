class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.rbegin() , nums.rend());

        int ans = 0;
        for(int i=0; i<n-1; i++) {
            if(nums[i] != nums[i+1]) {
                ans += (i + 1);
            }
            else if(nums[i+1] == nums[n-1]) {
                break;
            }
        }
        return ans;
    }
};