class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> prefix(n);
        vector<long long> profit(n);

        prefix[0] = prices[0];
        profit[0] = (prices[0] * strategy[0]);

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + prices[i];
            profit[i] = profit[i-1] + (prices[i] * strategy[i]);
        }

        long long ans = profit[n - 1];

        int i = 0;
        for(int j=0; j<n; j++) {
            while((j - i + 1) > k) {
                i++;
            }

            if((j - i + 1) == k) {
                long long value1 = prefix[j] - prefix[i + ((k  / 2) - 1)];
                long long value2 = ((i != 0) ? profit[i - 1] : 0) + ((j != n - 1) ? profit[n - 1] - profit[j] : 0);
                ans = max(ans , value1 + value2);
            }
        }
        return ans;
    }
};