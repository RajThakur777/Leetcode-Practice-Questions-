class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();

        char a = s1[0];
        char b = s1[1];
        char c = s1[2];
        char d = s1[3];

        if(((a == s2[0] && c == s2[2]) || (a == s2[2] && c == s2[0])) && ((b == s2[3] && d == s2[1]) || (b == s2[1] && d == s2[3]))) {
            return true;
        }
        return false;
    }
};