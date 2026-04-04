class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();

        map<string , long long> mpp;

        for(int i=0; i<n; i++) {
            int w = rectangles[i][0];
            int h = rectangles[i][1];

            int gcd = __gcd(w , h);

            int g1 = (w / gcd);
            int g2 = (h / gcd);

            string str = to_string(g1) + " / " + to_string(g2);

            mpp[str]++;
        }

        long long ans = 0;
        for(auto it : mpp) {
            if(it.second >= 2) {
                ans += ((it.second) * 1LL * (it.second - 1)) / 2;
            }
        }
        return ans;
    }
};