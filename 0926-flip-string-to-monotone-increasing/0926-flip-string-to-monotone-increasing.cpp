class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        int cnt_1 = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                cnt_1++;
            }
        }

        if(cnt_1 == 0 || cnt_1 == n) {
            return 0;
        }

        vector<int> prefix_ones(n);
        vector<int> suffix_zeroes(n);

        prefix_ones[0] = 0;

        for(int i=1; i<n; i++) {
            prefix_ones[i] = prefix_ones[i-1] + (s[i-1] == '1');
        }

        suffix_zeroes[n-1] = 0;

        for(int i=n-2; i>=0; i--) {
            suffix_zeroes[i] = suffix_zeroes[i+1] + (s[i+1] == '0');
        }

        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                ans = min(ans , prefix_ones[i] + suffix_zeroes[i]);
            }
        }

        ans = min(ans , cnt_1);
        ans = min(ans , n - cnt_1);
        return ans;
    }
};