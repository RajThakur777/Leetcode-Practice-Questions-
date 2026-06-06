class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());

        int prev_x = intervals[0][0];
        int prev_y = intervals[0][1];

        vector<vector<int>> res;

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= prev_y) {
                prev_x = min(prev_x , intervals[i][0]);
                prev_y = max(prev_y , intervals[i][1]);
            }
            else {
                res.push_back({prev_x , prev_y});
                prev_x = intervals[i][0];
                prev_y = intervals[i][1];
            }
        }

        res.push_back({prev_x , prev_y});

        long long val = (brightness + 2) / 3;

        long long ans = 0;

        for(int i=0; i<res.size(); i++) {
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }

        for(int i=0; i<res.size(); i++) {
            ans += (res[i][1] - res[i][0] + 1);
        }

        return (ans * 1LL * val);
    }
};