class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();

        string str;
        int i = 0;

        while(i < k) {
            str += s[i];
            i++;
        }

        reverse(str.begin() , str.end());

        string s1;

        while(i < n) {
            s1 += s[i];
            i++;
        }

        return str + s1;
    }
};