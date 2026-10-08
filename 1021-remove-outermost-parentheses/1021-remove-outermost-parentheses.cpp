class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        string ans;

        int idx = 0;

        int c = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                c++;
            }
            else {
                c--;
            }

            if(c == 0) {
                ans += s.substr(idx+1 , i-idx-1);
                idx = i+1;
            }
        }

        return ans;
    }
};