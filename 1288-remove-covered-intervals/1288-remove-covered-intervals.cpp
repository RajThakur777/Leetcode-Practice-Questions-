class Solution {
public:

    static bool cmp(vector<int> &a , vector<int> &b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }

        return a[1] > b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end() , cmp);

        int cnt = 1;
        int prev_x = intervals[0][0];
        int prev_y = intervals[0][1];

        for(int i=1; i<n; i++) {
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(prev_x <= a && b <= prev_y) {
                continue;
            }
            else {
                cnt++;
                prev_x = min(prev_x , a);
                prev_y = max(prev_y , b);
            }
        }
        return cnt;
    }
};