class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sum = nums1[i] + nums2[j];

                mpp[sum]++;
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sum = nums3[i] + nums4[j];

                int req = 0;

                if(sum == 0) {
                    req = 0;
                }
                else {
                    req = -sum;
                }

                if(mpp.find(req) != mpp.end()) {
                    ans += mpp[req];
                }
            }
        }
        return ans;
    }
};