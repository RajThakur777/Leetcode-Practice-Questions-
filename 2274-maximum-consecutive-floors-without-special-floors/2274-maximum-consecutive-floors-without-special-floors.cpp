class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();

        int ans = 0;

        sort(special.begin() , special.end());

        int prev = special[0];

        ans = max(ans , special[0] - bottom);

        for(int i=1; i<n; i++) {
            ans = max(ans , (special[i] - prev - 1));
            prev = special[i];
        }

        ans = max(ans , top - special[n-1]);
        return ans;
    }
};