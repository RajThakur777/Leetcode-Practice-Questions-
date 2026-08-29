class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        int ans1 = 0;

        for(int i=0; i<n-1; i++) {
            int g1 = 0;
            for(int j=0; j<=i; j++) {
                g1 = __gcd(g1 , nums[j]);
            }

            int g2 = 0;
            for(int j=i+1; j<n; j++) {
                g2 = __gcd(g2 , nums[j]);
            }

            if(g1 == g2) {
                ans1++;
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {
            vector<int> arr;

            for(int j=0; j<n; j++) {
                if(j != i) {
                    arr.push_back(nums[j]);
                }
            }

            int sz = arr.size();

            vector<int> prefix(sz);
            prefix[0] = arr[0];

            for(int j=1; j<sz; j++) {
                prefix[j] = __gcd(prefix[j-1] , arr[j]);
            }

            vector<int> suffix(sz);
            suffix[sz-1] = arr[sz-1];

            for(int j=sz-2; j>=0; j--) {
                suffix[j] = __gcd(suffix[j+1] , arr[j]);
            }

            int ans = 0;

            for(int k=0; k<arr.size()-1; k++) {
                int g1 = prefix[k];
                int g2 = suffix[k+1];

                if(g1 == g2) {
                    ans++;
                }
            }

            cnt = max(cnt , ans);
        }

        cnt = max(cnt , ans1);

        return cnt;
    }
};