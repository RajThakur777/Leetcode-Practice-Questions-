class Solution {
public:
    bool validDigit(int n, int x) {
        string str = to_string(n);

        int cnt = 0;
        for(int i=0; i<str.size(); i++) {
            if((str[i] - '0') == x) {
                cnt++;
            }
        }

        return (cnt > 0 && (str[0] - '0' != x));
    }
};