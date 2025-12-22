class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            set<char> st;
            for(int j=i; j<n; j++) {
                if(st.find(s[j]) == st.end()) {
                    st.insert(s[j]);
                } 
                else {
                    break;
                }
            }
            ans = max(ans , (int)st.size());
        }
        return ans;
    }
};