class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int cnt_0 = 0;
        int cnt_1 = 0;
        int cnt_2 = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                cnt_0++;
            }
            else if(nums[i] == 1) {
                cnt_1++;
            }
            else {
                cnt_2++;
            }
        }

        int i = 0;
        while(i < n && cnt_0 > 0) {
            nums[i] = 0;
            cnt_0--;
            i++;
        }

        while(i < n && cnt_1 > 0) {
            nums[i] = 1;
            cnt_1--;
            i++;
        }

        while(i < n && cnt_2 > 0) {
            nums[i] = 2;
            cnt_2--;
            i++;
        }
    }
};