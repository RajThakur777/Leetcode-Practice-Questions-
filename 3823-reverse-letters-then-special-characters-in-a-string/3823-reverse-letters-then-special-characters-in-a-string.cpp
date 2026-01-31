class Solution {
public:

    bool isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z');
    }
    
    string reverseByType(string s) {
        int n = s.size();

        string s1;
        string s2;

        for(int i=0; i<n; i++) {
            if(isAlpha(s[i])) {
                s1 += s[i];
            }
            else {
                s2 += s[i];
            }
        }

        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());

        int idx1 = 0;

        for(int i=0; i<n; i++) {
            if(isAlpha(s[i])) {
                s[i] = s1[idx1];
                idx1++;
            }
        }

        int idx2 = 0;
        for(int i=0; i<n; i++) {
            if(!isAlpha(s[i])) {
                s[i] = s2[idx2];
                idx2++;
            }
        }
        return s;
    }
};