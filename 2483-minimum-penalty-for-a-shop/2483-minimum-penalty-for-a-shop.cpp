class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = (customers[0] == 'N');
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (customers[i] == 'N');
        }

        suffix[n - 1] = (customers[n - 1] == 'Y');
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y');
        }

        int ans = INT_MAX, idx = 0;

        for (int i = 0; i <= n; i++) {
            int penalty;
            if (i == 0) penalty = suffix[0];
            else if (i == n) penalty = prefix[n - 1];
            else penalty = prefix[i - 1] + suffix[i];

            if (penalty < ans) {
                ans = penalty;
                idx = i;
            }
        }
        return idx;
    }
};
