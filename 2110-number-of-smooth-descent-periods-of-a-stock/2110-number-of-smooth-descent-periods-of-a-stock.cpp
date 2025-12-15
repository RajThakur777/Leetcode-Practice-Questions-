class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        long long ans = 0;

        long long cnt = 1;

        int prev = prices[0];

        for(int i=1; i<n; i++) {
            if(prev - prices[i] == 1) {
                cnt++;
                prev = prices[i];
            }
            else {
                if(cnt > 0) {
                    ans += (((cnt) * (cnt + 1))) / 2;
                    cnt = 1;
                }
                prev = prices[i];
            }
        }
        if(cnt > 0) {
            ans += (((cnt) * (cnt + 1))) / 2;
            cnt = 1;
        }
        return ans;
    }
};