class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();

        int maxi = -1;
        int c = 0;

        int ans = 0;

        for(int i=0; i<n; i++) {
            maxi = max(maxi , flips[i] - 1);
            c++;

            if((i + 1) == c && (i) == maxi) {
                ans++;
            }
        }

        return ans;
    }
};