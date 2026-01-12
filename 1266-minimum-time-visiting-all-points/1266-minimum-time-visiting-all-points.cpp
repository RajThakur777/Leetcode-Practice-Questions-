class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) { 
        int n = points.size();

        int ans = 0;

        for(int i=0; i<n-1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            int d1 = abs(x1 - x2);
            int d2 = abs(y1 - y2);

            if(d1 == d2) {
                ans += (d1);
            }
            else {
                if(d1 < d2) {
                    ans += d1;
                    ans += d2 - d1;
                }
                else {
                    ans += d2;
                    ans += d1 - d2;
                }
            }
        }
        return ans;
    }
};