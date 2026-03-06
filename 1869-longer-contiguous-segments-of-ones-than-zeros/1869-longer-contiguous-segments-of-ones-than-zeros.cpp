class Solution {
public:

    int lcs(string s , char ch) {
        int ans = 0;
        int len = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ch) {
                len++;
            }
            else {
                if(len > 0) {
                    ans = max(ans , len);
                }
                len = 0;
            }
        }
        if(len > 0) {
            ans = max(ans , len);
        }
        return ans;
    } 

    bool checkZeroOnes(string s) {
        int n = s.size();

        int zero = lcs(s , '0');
        int one = lcs(s , '1');

        return (one > zero);
    }
};