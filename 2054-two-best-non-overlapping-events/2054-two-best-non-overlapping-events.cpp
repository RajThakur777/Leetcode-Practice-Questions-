class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<int> suffix(n);
        suffix[n-1] = events[n-1][2];

        for(int i=n-2; i>=0; i--) {
            suffix[i] = max(suffix[i+1] , events[i][2]);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int st = events[i][0];
            int ed = events[i][1];
            int v = events[i][2];

            auto idx = lower_bound(events.begin() , events.end() , vector<int>{ed + 1 , INT_MIN , INT_MIN});

            if(idx != events.end()) {
                int j = idx - events.begin();

                ans = max(ans , v + suffix[j]);
            }
            else {
                ans = max(ans , v);
            }
        }
        return ans;
    }
};