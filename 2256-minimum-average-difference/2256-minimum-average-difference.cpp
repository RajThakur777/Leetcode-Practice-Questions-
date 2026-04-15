class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int ans = INT_MAX;
        int idx = -1;

        for(int i=0; i<n; i++) {
            long long s1 = prefix[i];
            long long s2 = prefix[n-1] - prefix[i];

            int len1 = (i+1);
            int len2 = (n - i - 1);

            int value = 0;

            if(len2 == 0) {
                int a1 = (s1 / len1);
                value = a1;
            }
            else {
                int a1 = (s1 / len1);
                int a2 = (s2 / len2);

                value = abs(a1 - a2);
            }

            if(value < ans) {
                ans = value;
                idx = i;
            }
        }
        return idx;
    }
};