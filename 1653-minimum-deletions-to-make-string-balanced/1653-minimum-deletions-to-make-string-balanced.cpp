class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int cnt = 0;

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(s[i] == 'b') {
                st.push(s[i]);
            }
            else {
                if(!st.empty()) {
                    cnt++;
                    st.pop();
                }
            }
        }
        return cnt;
    }
};