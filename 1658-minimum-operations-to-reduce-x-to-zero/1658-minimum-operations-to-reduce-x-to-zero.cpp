class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> prefix(n) , suffix(n);

        prefix[0] = nums[0];
        
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        if(prefix[n-1] < x) {
            return -1;
        }

        suffix[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + nums[i];
        }

        reverse(suffix.begin() , suffix.end());

        int idx1 = lower_bound(prefix.begin() , prefix.end() , x) - prefix.begin();

        int op1 = 0;

        if(idx1 != n && prefix[idx1] == x) {
            op1 = (idx1 + 1);
        }
        else {
            op1 = INT_MAX;
        }

        int idx2 = lower_bound(suffix.begin() , suffix.end() , x) - suffix.begin();

        int op2 = 0;

        if(idx2 != n && suffix[idx2] == x) {
            op2 = (idx2 + 1);
        }
        else {
            op2 = INT_MAX;
        }

        int ans = INT_MAX;

        for(int i=0; i<n-1; i++) {
            int val = prefix[i];

            int rem = (x - val);

            int v1 = (i + 1);

            int idx = lower_bound(suffix.begin() , suffix.end() , rem) - suffix.begin();

            if(idx != n && suffix[idx] == rem) {
                v1 += (idx + 1);

                ans = min(ans , v1);
            }
        }

        ans = min(ans , op1);
        ans = min(ans , op2);

        return (ans == INT_MAX ? -1 : ans);
    }
};