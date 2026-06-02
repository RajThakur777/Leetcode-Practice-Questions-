class Solution {
public:
    static bool cmp(pair<int , int> &a , pair<int , int> &b) {
        return (a.first + a.second) < (b.first + b.second);
    }

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

        sort(land.begin() , land.end() , cmp);
        sort(water.begin() , water.end() , cmp);

        int t1 = land[0].first;
        int d1 = land[0].second;

        int res1 = INT_MAX;
        for(int i=0; i<n; i++) {
            int t2 = water[i].first;
            int d2 = water[i].second;

            int val = t1 + d1;

            if(val < t2) {
                val += (t2 - val);
                val += d2; 
            }
            else {
                val += d2;
            }

            res1 = min(res1 , val);
        }

        int t2 = water[0].first;
        int d2 = water[0].second;

        int res2 = INT_MAX;
        for(int i=0; i<m; i++) {
            int t1 = land[i].first;
            int d1 = land[i].second;

            int val = t2 + d2;

            if(val < t1) {
                val += (t1 - val);
                val += d1; 
            }
            else {
                val += d1;
            }

            res2 = min(res2 , val);
        }

        return min(res1 , res2);
    }
};