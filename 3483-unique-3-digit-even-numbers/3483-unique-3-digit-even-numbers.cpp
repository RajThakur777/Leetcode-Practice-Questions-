class Solution {
public:

    bool isEven(string ans) {
        return (ans[2] - '0') % 2 == 0;
    }

    void solve(vector<int> &digits , set<int> &st , string ans , set<string> &res) {
        if(ans.size() == 3) {
            if(ans[0] != '0' && isEven(ans)) {
                res.insert(ans);
            }
            return;
        }

        for(int i=0; i<digits.size(); i++) {
            if(st.find(i) == st.end()) {
                st.insert(i);

                ans.push_back((char)(digits[i] + '0'));

                solve(digits , st , ans , res);

                st.erase(i);

                ans.pop_back();
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        set<int> st;
        
        set<string> st2;

        string str;

        solve(digits , st , str , st2);

        return st2.size();
    }
};