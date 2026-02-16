class Solution {
public:
    int reverseBits(int n) {
        string res;

        for(int i=0; i<32; i++) {
            if((n & (1 << i)) > 0) {
                res += '1';
            }
            else {
                res += '0';
            }
        }

        int num = 0;
        int idx = 0;

        for(int i=res.size()-1; i>=0; i--) {
            if(res[i] == '1') {
                num += pow(2 , idx);
            }
            idx++;
        }
        return num;
    }
};