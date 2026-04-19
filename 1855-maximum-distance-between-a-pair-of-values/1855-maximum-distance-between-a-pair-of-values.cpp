class Solution {
public:

    int solve(int x , vector<int> &nums2) {
        int l = 0;
        int r = nums2.size() - 1;

        int ans = -1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums2[mid] >= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            int ele = nums1[i];

            int l = solve(ele , nums2);

            if(l == -1) {
                continue;
            }

            ans = max(ans , (l - i));
        }
        return ans;
    }
};