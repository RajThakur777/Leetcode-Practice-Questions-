class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();

        vector<pair<int , int>> vec;

        for(int i=0; i<n; i++) {
            int l = logs[i][0];
            int r = logs[i][1];

            vec.push_back({l , +1});
            vec.push_back({r , -1});
        }

        sort(vec.begin() , vec.end());

        int ans = 0;
        int cnt = 0;

        int year = INT_MAX;

        for(int i=0; i<vec.size(); i++) {
            cnt += vec[i].second;

            if(cnt > ans) {
                ans = cnt;
                year = vec[i].first;
            }
            else if(cnt == ans) {
                ans = cnt;
                year = min(year , vec[i].first);
            }
        }
        return year;
    }
};