class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<string> st;

        for(int deno = 2; deno<=n; deno++) {
            for(int num=1; num<=deno; num++) {
                int gcd = __gcd(num , deno);

                int a1 = (num / gcd);
                int a2 = (deno / gcd);

                string s1 = to_string(a1);
                string s2 = to_string(a2);

                if(s1 != s2 && st.find(s1) == st.end()) {
                    string res = s1 + "/" + s2;

                    st.insert(res);
                }
            }
        }

        vector<string> ans;

        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};