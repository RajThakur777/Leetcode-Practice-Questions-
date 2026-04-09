class Solution {
public:

    bool solve(string s , int len) {
        string str = s.substr(0 , len);

        sort(str.begin() , str.end());

        for(int i=len; i<s.size(); i+=len) {
            string s1 = s.substr(i , len);

            sort(s1.begin() , s1.end());

            if(s1 != str) {
                return false;
            }
        }
        return true;
    }

    int minAnagramLength(string s) {
        int n = s.size();

        for(int len=1; len<n; len++) {
            if(n % len == 0 && solve(s , len)) {
                return len;
            }
        }
        return n;
    }
};