class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        long long ans = 0;

        vector<pair<int , int>> vec;

        for(int i=0; i<n; i++) {
            vec.push_back({intervals[i][0] , intervals[i][1]});
        }

        sort(vec.begin() , vec.end());

        for(int i=0; i<n; i++) {
            int x1 = intervals[i][0];
            int y1 = intervals[i][1];

            int idx = upper_bound(vec.begin() , vec.end() , make_pair(y1 , INT_MAX)) - vec.begin();

            ans += (idx - i - 1);
        }

        return ans;
    }
};