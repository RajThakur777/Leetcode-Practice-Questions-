class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        string ans;

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(s[i] == ')') {
                string r;
                while(!st.empty() && st.top() != '(') {
                    r += st.top();
                    st.pop();
                }

                st.pop();

                for(int j=0; j<r.size(); j++) {
                    st.push(r[j]);
                }
            }
            else {
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};