class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<int> diff(1002 , 0);

        for(int i=0; i<n; i++) {
            int val = trips[i][0];
            int l = trips[i][1];
            int r = trips[i][2];

            diff[l] += val;
            diff[r] -= val;
        }

        for(int i=1; i<1002; i++) {
            diff[i] += diff[i-1];
        }

        for(int i=0; i<1002; i++) {
            if(diff[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};