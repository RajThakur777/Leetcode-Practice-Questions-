class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int l = k1 + k2;

        vector<int> diff((int)(1e5+1));

        for(int i=0; i<nums1.size(); i++) {
            diff[abs(nums1[i] - nums2[i])]++;
        }

        for(int i=1e5; i>=1; i--) {
            int x = diff[i];

            if(x <= l) {
                diff[i-1] += diff[i];
                diff[i] = 0;
                l -= x;
            }
            else {
                diff[i] -= l;
                diff[i-1] += l;

                break;
            }
        }

        long long ans = 0;

        for(int i=1; i<=1e5; i++) {
            ans += ((diff[i] * 1LL * (i * 1LL * i)));
        }

        return ans;
    }
};