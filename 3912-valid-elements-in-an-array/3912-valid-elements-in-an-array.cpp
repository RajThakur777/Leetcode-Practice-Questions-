class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return {nums[0]};
        }

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n-1; i++) {
            int ele = nums[i];

            bool f1 = true;
            bool f2 = true;

            int idx = i;

            for(int i=idx-1; i>=0; i--) {
                if(nums[i] >= ele) {
                    f1 = false;
                    break;
                }
            }

            for(int i=idx+1; i<n; i++) {
                if(nums[i] >= ele) {
                    f2 = false;
                    break;
                }
            }

            if(f1 || f2) {
                ans.push_back(ele);
            }
        }
        ans.push_back(nums[n-1]);

        return ans;
    }
};