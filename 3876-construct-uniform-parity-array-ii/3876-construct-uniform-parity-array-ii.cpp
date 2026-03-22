class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin() , nums1.end());

        if(nums1[0] % 2 != 0) {
            return true;
        }
        else {
            bool f = true;
            for(int i=0; i<n; i++) {
                if(nums1[i] % 2 != 0) {
                    f = false;
                    break;
                }
            }

            if(f) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};