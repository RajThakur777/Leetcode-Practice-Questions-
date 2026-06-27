class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();

        int prev = (s[0] - 'a');
        int cnt = 1;

        int ans = 0;

        for(int i=1; i<n; i++) {
            if((prev + 1) + 'a' == s[i]) {
                cnt++;
                prev++;
            }
            else {
                ans = max(ans , cnt);
                prev = (s[i] - 'a');
                cnt = 1;
            }
        }

        ans = max(ans , cnt);

        return ans;
    }
};