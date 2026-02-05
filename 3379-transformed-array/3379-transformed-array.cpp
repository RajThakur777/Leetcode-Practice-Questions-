class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {  
        int n = nums.size();

        vector<int> ans;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            if(ele == 0) {
                ans.push_back(0);
            }
            else if(ele > 0) {
                int j = i;
                int cnt = ele;
                while(cnt != 0) {
                    j = (j + 1) % n;
                    cnt--;
                }
                ans.push_back(nums[j]);
            }
            else {
                int j = i;
                int cnt = abs(ele);
                while(cnt != 0) {
                    j = (j - 1 + n) % n;
                    cnt--;
                }
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};