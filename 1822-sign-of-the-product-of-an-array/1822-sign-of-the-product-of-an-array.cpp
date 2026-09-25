class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        
        int neg = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                zero++;
            }
            else if(nums[i] < 0) {
                neg++;
            }
        }

        if(zero > 0) {
            return 0;
        }

        if(neg % 2 == 0) {
            return 1;
        }

        return -1;
    }
};