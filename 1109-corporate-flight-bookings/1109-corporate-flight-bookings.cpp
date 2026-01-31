class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int sz = bookings.size();

        vector<int> diff(n+1);

        for(int i=0; i<sz; i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int val = bookings[i][2];

            diff[l] += val;
            if(r + 1 <= n) {
                diff[r + 1] -= val;
            }
        }

        for(int i=1; i<=n; i++) {
            diff[i] += diff[i-1];
        }

        vector<int> ans(n);
        for(int i=1; i<=n; i++) {
            ans[i-1] = diff[i];
        }
        return ans;
    }
};