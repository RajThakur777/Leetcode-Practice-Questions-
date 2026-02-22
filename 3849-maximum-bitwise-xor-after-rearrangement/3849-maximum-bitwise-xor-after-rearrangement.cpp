class Solution {
public:
    string maximumXor(string s, string t) {   
        int n = s.size();

        int ones = 0;
        int zeroes = 0;

        for(int i=0; i<t.size(); i++) {
            if(t[i] == '1') {
                ones++;
            }
            else {
                zeroes++;
            }
        }

        string res(n , ' ');

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                if(zeroes > 0) {
                    res[i] = '0';
                    zeroes--;
                }
                else {
                    res[i] = '1';
                    ones--;
                }
            }
            else if(s[i] == '0') {
                if(ones > 0) {
                    res[i] = '1';
                    ones--;
                }
                else {
                    res[i] = '0';
                    zeroes--;
                }
            }
        }

        string a = s;
        string b = res;

        string ans(n , ' ');

        for(int i=0; i<n; i++) {
            if(s[i] == '1' && res[i] == '1') {
                ans[i] = '0';
            }
            else if((s[i] == '1' && res[i] == '0') || (s[i] == '0' && res[i] == '1')) {
                ans[i] = '1';
            }
            else if(s[i] == '0' && res[i] == '0') {
                ans[i] = '0';
            }
        }
        return ans;
    }
};