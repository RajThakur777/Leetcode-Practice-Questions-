class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1 , 0);

        for(int i=0; i<bookings.size(); i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int x = bookings[i][2];

            diff[l] += x;
            if(r+1 <= n) {
                diff[r+1] -= x;
            }
        }

        for(int i=1; i<=n; i++) {
            diff[i] += diff[i-1];
        }

        vector<int> ans;
        for(int i=1; i<=n; i++) {
            ans.push_back(diff[i]);
        }

        return ans;
    }
};