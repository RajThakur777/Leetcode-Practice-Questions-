class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        int ans = 0;

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) {
                    ans++;
                }
                else {
                    st.pop();
                }
            }
        }

        ans += (st.size());

        return ans;
    }
};