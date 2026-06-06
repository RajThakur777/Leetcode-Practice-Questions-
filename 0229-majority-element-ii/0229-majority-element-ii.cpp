class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0;
        int ele1 = 0;

        int cnt2 = 0;
        int ele2 = 0;

        for(int i=0; i<n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]) {
                cnt1++;
            }
            else if(ele2 == nums[i]) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        int res1 = 0;
        int res2 = 0;
        for(int i=0; i<n; i++) {
            if(ele1 == nums[i]) {
                res1++;
            }
            else if(ele2 == nums[i]) {
                res2++;
            }
        }

        vector<int> ans;

        if(res1 > (n / 3)) {
            ans.push_back(ele1);
        }

        if(res2 > (n / 3)) {
            ans.push_back(ele2);
        }
        return ans;
    }
};