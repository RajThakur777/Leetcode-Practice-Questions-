class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        stack<char> st;

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else {
                st.pop();

                if(s[i-1] == '(') {
                    int d = st.size();

                    ans += ((1 << (d)));
                }
            }
        }
        return ans;
    }
};