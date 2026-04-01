class Solution {
public:
    string removeStars(string s) {
        int n = s.size();

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(st.empty() || s[i] != '*') {
                st.push(s[i]);
            }
            else if(s[i] == '*'){
                if(!st.empty() && st.top() != '*') {
                    st.pop();
                }
            }
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};