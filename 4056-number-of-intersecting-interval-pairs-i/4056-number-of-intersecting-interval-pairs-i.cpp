class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = intervals[i][0];
                int y1 = intervals[i][1];

                int x2 = intervals[j][0];

                if(x2 <= y1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};