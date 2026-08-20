class Solution {
public:
    int n;

    void solve(int idx , string &s , set<string> &st , vector<string> &vec , vector<string> &arr) {
        if(idx == n) {
            string ans;
            
            for(int i=0; i<arr.size()-1; i++) {
                ans += arr[i];

                ans += " ";
            }

            ans += arr[arr.size() - 1];

            vec.push_back(ans);

            return;
        }

        for(int i=idx; i<n; i++) {
            string str = s.substr(idx , (i - idx + 1));

            if(st.find(str) != st.end()) {
                arr.push_back(str);

                solve(i+1 , s , st , vec , arr);

                arr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        set<string> st;

        for(auto str : wordDict) {
            st.insert(str);
        }

        vector<string> vec;

        vector<string> arr;

        solve(0 , s , st , vec , arr);

        return vec;
    }
};