class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> ans(n , -1);

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[intervals[i][0]] = i;
        }

        vector<int> vec;
        for(int i=0; i<n; i++) {
            vec.push_back(intervals[i][0]);
        }

        sort(vec.begin() , vec.end());

        for(int i=0; i<n; i++) {
            int x = intervals[i][1];

            int idx = lower_bound(vec.begin() , vec.end() , x) - vec.begin();

            if(idx != vec.size()) {
                int val = mpp[vec[idx]];

                ans[i] = val;
            }
        }
        return ans;
    }
};