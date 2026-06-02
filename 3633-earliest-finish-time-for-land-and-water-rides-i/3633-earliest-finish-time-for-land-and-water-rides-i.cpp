class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int , int>> land;

        for(int i=0; i<landStartTime.size(); i++) {
            int t = landStartTime[i];
            int d = landDuration[i];

            land.push_back({t , d});
        }

        vector<pair<int , int>> water;

        for(int i=0; i<waterStartTime.size(); i++) {
            int t = waterStartTime[i];
            int d = waterDuration[i];

            water.push_back({t , d});
        }

        int ans = INT_MAX;

        int m = land.size();
        int n = water.size();

        for(int i=0; i<m; i++) {
            int t1 = land[i].first;
            int d1 = land[i].second;
            for(int j=0; j<n; j++) {
                int t2 = water[j].first;
                int d2 = water[j].second;

                int res1 = t1 + d1;
                if(t2 > res1) {
                    res1 += (t2 - res1);
                    res1 += d2;
                }
                else {
                    res1 += d2;
                }

                int res2 = t2 + d2;
                if(t1 > res2) {
                    res2 += (t1 - res2);
                    res2 += d1;
                }
                else {
                    res2 += d1;
                }

                int mini = min(res1 , res2);

                ans = min(ans , mini);
            }
        }
        return ans;
    }
};