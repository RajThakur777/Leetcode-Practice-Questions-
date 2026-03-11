class Solution {
public:
    int findComplement(int n) {
        if(n == 0) return 1;

        int bits = 31 - __builtin_clz(n);

        string str;
        for(int i = 0; i <= bits; i++) {
            if((n & (1 << i)) > 0) {
                str += '0';
            }
            else {
                str += '1';
            }
        }

        reverse(str.begin() , str.end());

        int idx = 0;
        int ans = 0;

        for(int i = str.size() - 1; i >= 0; i--) {
            if(str[i] == '1') {
                ans += pow(2 , idx);
            }
            idx++;
        }

        return ans;
    }
};