class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        double ans = 0.0;

        sort(prices.begin() , prices.end());
        sort(discounts.begin() , discounts.end());

        int i = n-1;
        int j = m-1;

        while(i >= 0 && j >= 0) {
            double p = (prices[i] * (100 - discounts[j])) / 100.0;

            ans += (double)(p);

            i--;
            j--;
        }

        if(i < 0) {
            return ans;
        }

        while(i >= 0) {
            ans += (double)(prices[i]);
            i--;
        }

        return ans;
    }
};