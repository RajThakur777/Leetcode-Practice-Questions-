class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                st.push(s[i]);
            }
            else if(s[i] == 'b') {
                if(st.empty()) {
                    return false;
                }
                else {
                    st.push(s[i]);
                }
            }
            else {
                if(st.empty()) {
                    return false;
                }

                if(!st.empty() && st.size() >= 2) {
                    if(st.top() == 'b') {
                        st.pop();

                        if(st.top() == 'a') {
                            st.pop();
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
        } 
        return (st.empty());
    }
};