class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int prev = nums[0];
        int cnt = 1;

        for(int j=1; j<n; j++) {
            if(nums[j] != prev) {
                i++;
                cnt++;
                nums[i] = nums[j];
                prev = nums[j];
            }
        }
        return cnt;
    }
};