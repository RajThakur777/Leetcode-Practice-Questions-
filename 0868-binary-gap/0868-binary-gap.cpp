class Solution {
public:
    int binaryGap(int n) {
        string res;

        int bits = 31 - __builtin_clz(n);

        for(int i=0; i<=bits; i++) {
            if((n & (1 << i)) > 0) {
                res += '1';
            }
            else {
                res += '0';
            }
        }

        int ans = INT_MIN;

        int idx = -1;
        for(int i=0; i<res.size(); i++) {
            if(res[i] == '1') {
                idx = i;
                break;
            }
        }

        if(idx == -1) return 0;

        for(int i=idx+1; i<res.size(); i++) {
            if(res[i] == '1') {
                ans = max(ans , i - idx);
                idx = i;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};