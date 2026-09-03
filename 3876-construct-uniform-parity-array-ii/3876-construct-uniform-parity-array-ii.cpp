class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin() , nums1.end());

        bool f1 = true;
        bool f2 = true;

        //all odd;
        int odd = -1;
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 != 0) {
                odd = nums1[i];
            }
            else {
                if(odd == -1) {
                    f1 = false;
                    break;
                }
            }
        }

        //all even
        int o = -1;
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 != 0) {
                f2 = false;
                break;
            }
        }

        return (f1 || f2);
    }
};