class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {   
        int n = nums.size();

        vector<int> ans(n , -1);

        for(int i=0; i<n; i++) {
            int y = nums[i];
            for(int j=31; j>=0; j--) {
                if((nums[i] & (1 << j)) > 0) {
                    int x = (nums[i] & ~ (1 << j));

                    if(((x) | (x + 1)) == y) {
                        ans[i] = x;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};