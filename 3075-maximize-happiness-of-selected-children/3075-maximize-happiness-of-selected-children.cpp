class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.begin() , happiness.end());

        long long ans = 0;

        int cnt = 1;
        ans = happiness[n-1];
        k--;

        for(int i=n-2; i>=0; i--) {
            int v = happiness[i] - cnt;

            if(k == 0) break;

            if(v <= 0) {
                break;
            }
            else {
                ans += v;
                k--;
                cnt++;
            }
        }
        return ans;
    }
};