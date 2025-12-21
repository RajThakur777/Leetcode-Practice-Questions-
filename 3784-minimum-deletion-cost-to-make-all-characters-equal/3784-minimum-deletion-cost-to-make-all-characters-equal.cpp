class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = 0;

        for(int i=0; i<cost.size(); i++) {
            total += cost[i];
        }

        vector<long long> freq(26 , 0);

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];

            freq[ch-'a'] += cost[i];
        }

        long long ans = LLONG_MAX;
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                ans = min(ans , (total - freq[i]));
            }
        }
        return (ans == LLONG_MAX) ? 0 : ans;
    }
};