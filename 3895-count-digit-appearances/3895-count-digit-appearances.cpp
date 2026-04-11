class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            while(ele > 0) {
                int dig = (ele % 10);
                if(dig == digit) {
                    ans++;
                }
                ele /= 10;
            }
        }
        return ans;
    }
};