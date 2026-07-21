class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());

        int prev_x = intervals[0][0];
        int prev_y = intervals[0][1];

        vector<vector<int>> ans;

        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= prev_y) {
                prev_x = min(prev_x , intervals[i][0]);
                prev_y = max(prev_y , intervals[i][1]);
            }
            else {
                ans.push_back({prev_x , prev_y});
                prev_x = intervals[i][0];
                prev_y = intervals[i][1];
            }
        }

        ans.push_back({prev_x , prev_y});

        return ans;
    }
};