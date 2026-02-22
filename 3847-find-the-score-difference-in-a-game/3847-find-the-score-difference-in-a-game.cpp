class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int A = 1;
        int B = 0;

        int ans1 = 0;
        int ans2 = 0;

        for(int i=0; i<n; i++) {
            if((i + 1) %  6 == 0) {
                A = (A == 0 ? 1 : 0);
                B = (B == 0 ? 1 : 0);
            }

            if((nums[i] % 2 != 0)) {
                A = (A == 0 ? 1 : 0);
                B = (B == 0 ? 1 : 0);
            }

            if(A == 1) {
                ans1 += nums[i];
            }
            else if(B == 1) {
                ans2 += nums[i];
            }
        }
        return ans1 - ans2;
    }
};