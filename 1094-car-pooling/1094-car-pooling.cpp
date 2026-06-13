class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<pair<int , int>> vec;

        for(int i=0; i<n; i++) {
            int l = trips[i][1];
            int r = trips[i][2];
            int x = trips[i][0];

            vec.push_back({l , + x});
            vec.push_back({r , -x});
        }

        sort(vec.begin() , vec.end());

        int cnt = 0;
        for(int i=0; i<vec.size(); i++) {
            cnt += vec[i].second;

            if(cnt > capacity) {
                return false;
            }
        }
        return true;
    }
};