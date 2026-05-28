class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(nums.begin() , nums.end());
        int maxi = *max_element(nums.begin() , nums.end());

        int idx1 = -1;
        int idx2 = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] == mini) {
                idx1 = i;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(nums[i] == maxi) {
                idx2 = i;
                break;
            }
        }

        if(idx1 < idx2) {
            int ans1 = idx1 + 1 + n - idx2;
            int ans2 = idx2 + 1;
            int ans3 = n - idx1;

            return min({ans1 , ans2 , ans3});
        }
        else {
            int ans1 = idx2 + 1 + n - idx1;
            int ans2 = idx1 + 1;
            int ans3 = n - idx2;

            return min({ans1 , ans2 , ans3});
        }
    }
};