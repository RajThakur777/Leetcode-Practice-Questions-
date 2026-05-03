class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i=0; i<n-1; i++) {
            int ele = nums[i];
            int cnt = 0;
            for(int j=i+1; j<n; j++) {
                if((nums[j] % 2 ) != (ele % 2)) {
                    cnt++;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};