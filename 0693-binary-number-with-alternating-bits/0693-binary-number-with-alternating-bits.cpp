class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bits = 31 - __builtin_clz(n);

        string str;

        for(int i=0; i<=bits; i++) {
            if((n & (1 << i)) > 0) {
                str += '1';
            }
            else {
                str += '0';
            }
        }

        for(int i=0; i<str.size()-1; i++) {
            if(str[i] == str[i+1]) return false;
        }
        return true;
    }
};