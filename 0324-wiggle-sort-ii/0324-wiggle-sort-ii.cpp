class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<int> temp(n);
        int idx = 1;

        int j = -1;
        for(int i=n-1; i>=0; i--) {
            if(idx < n) {
                temp[idx] = nums[i];
                idx += 2;
            }
            else {
                j = i;
                break;
            }
        }

        idx = 0;
        for(int k=j; k>=0; k--) {
            temp[idx] = nums[k];
            idx += 2;
        }

        nums = temp;
    }
};