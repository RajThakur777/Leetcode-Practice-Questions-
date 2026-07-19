class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string s1;
        string s2;
        string s3;

        int n = s.size();

        for(int i=0; i<n; i++) {
            if(s[i] == y) {
                s1 += s[i];
            }
            else if(s[i] == x) {
                s2 += s[i];
            }
            else {
                s3 += s[i];
            }
        }

        string ans = s1;
        ans += s3;
        ans += s2;

        return ans;
    }
};