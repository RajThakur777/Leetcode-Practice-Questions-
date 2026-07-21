class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        if(n == 1) {
            return (s[0] == '1');
        }

        if(n == 2) {
            int cnt = 0;
            for(int i=0; i<2; i++) {
                if(s[i] == '1') {
                    cnt++;
                }
            }

            return cnt;
        }

        int without_trade = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                without_trade++;
            }
        }

        int with_trade = 0;
        int total_ones = without_trade;

        vector<int> arr;

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    arr.push_back(cnt);
                }
                cnt = 0;
            }
        }

        if(cnt > 0) {
            arr.push_back(cnt);
        }        

        if(arr.size() == 1 || arr.size() == 0) {
            return total_ones;
        }

        for(int i=0; i<arr.size()-1; i++) {
            with_trade = max(with_trade , total_ones + (arr[i] + arr[i+1]));
        }

        return max(without_trade , with_trade);
    }
};