class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums1[i]]++;
        }

        for(int i=0; i<n; i++) {
            mpp[nums2[i]]++;
        }

        for(auto it : mpp) {
            if(it.second % 2 != 0) {
                return -1;
            }
        }

        map<int , int> mpp2;
        for(int i=0; i<n; i++) {
            mpp2[nums1[i]]++;
        }

        int ops = 0;

        for(auto it : mpp) {
            int ele = it.first;
            int freq = it.second;

            int f1 = mpp2[ele];
            int f2 = freq - f1;

            int half = (f1 + f2) / 2;

            if(f1 == half || f2 == half) {
                continue;
            }

            int transfer = max(f1 , f2) - half;
            ops += transfer;
        }
        return (ops / 2);
    }
};