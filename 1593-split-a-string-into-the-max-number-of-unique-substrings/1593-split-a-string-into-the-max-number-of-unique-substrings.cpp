class Solution {
public:

    int solve(int idx , string &s , set<string> &st) {
        if(idx == s.size()) {
            return 0;
        }

        int ans = 0;

        for(int i=idx; i<s.size(); i++) {
            string curr = s.substr(idx , i - idx + 1);

            if(st.find(curr) != st.end()) continue;

            st.insert(curr);
            
            ans = max(ans , 1 + solve(i+1 , s , st));

            st.erase(curr);
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        int n = s.size();

        set<string> st;

        return solve(0 , s , st);
    }
};