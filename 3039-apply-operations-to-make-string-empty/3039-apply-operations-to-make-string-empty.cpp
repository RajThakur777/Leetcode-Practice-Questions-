class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        set<char> st;
        for(int i=0; i<n; i++) {
            st.insert(s[i]);
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto it : mpp) {
            mini = min(mini , it.second);
            maxi = max(maxi , it.second);
        }

        if(mini == maxi) {
            string ans;
            for(int i=s.size()-1; i>=0; i--) {
                if(st.find(s[i]) != st.end()) {
                    ans += s[i];
                    st.erase(s[i]);
                }
            }

            reverse(ans.begin() , ans.end());

            return ans;
        }

        string ans;
        for(int i=s.size()-1; i>=0; i--) {
            if(st.find(s[i]) != st.end() && mpp[s[i]] == maxi) {
                ans += s[i];
                st.erase(s[i]);
            }
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};