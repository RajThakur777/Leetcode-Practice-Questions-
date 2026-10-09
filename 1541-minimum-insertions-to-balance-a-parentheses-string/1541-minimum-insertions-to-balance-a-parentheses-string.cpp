class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        stack<char> st;

        int ans = 0;

        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                st.push(s[i]);
                i++;
            }
            else {
                if(i+1 < n) {
                    if(s[i+1] == ')') {
                        if(!st.empty()) {
                            st.pop();
                            i += 2;
                        }
                        else {
                            ans++;
                            i += 2;
                        }
                    }
                    else {
                        if(!st.empty()) {
                            ans++;
                            st.pop();
                        }
                        else {
                            ans += 2;
                        }
                        i++;
                    }
                }
                else {
                    if(!st.empty()) {
                        st.pop();
                        ans++;
                    }
                    else {
                        ans += 2;
                    }
                    i++;
                }
            }
        }

        int sz = st.size();

        ans += (sz * 2);

        return ans;
    }
};