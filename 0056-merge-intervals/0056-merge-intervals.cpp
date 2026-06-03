class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());

        int p1 = intervals[0][0];
        int p2 = intervals[0][1];

        vector<vector<int>> ans;

        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= p2) {
                p1 = min(p1 , intervals[i][0]);
                p2 = max(p2 , intervals[i][1]);
            }
            else {
                ans.push_back({p1 , p2});
                p1 = intervals[i][0];
                p2 = intervals[i][1];
            }
        }
        
        ans.push_back({p1 , p2});

        return ans;
    }
};