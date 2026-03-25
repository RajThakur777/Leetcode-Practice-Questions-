class Solution {
public:

    int cnt(string str) {
        int ones = 0;

        for(int i=0; i<str.size(); i++) {
            ones += (str[i] == '1');
        }
        return ones;
    }

    static bool cmp(string a , string b) {
        if(a.size() == b.size()) {
            return a < b;
        }
        else {
            return (a.size() < b.size());
        }
    }

    string shortestBeautifulSubstring(string s, int k) {  
        int n = s.size();

        vector<string> ans;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                string str = s.substr(i , (j - i + 1));

                if(cnt(str) == k) {
                    ans.push_back(str);
                }
            }
        }
        if(ans.size() == 0) {
            return "";
        }

        sort(ans.begin() , ans.end() , cmp);

        for(auto it : ans) {
            cout<<it<<" ";
        }

        return ans[0];
    }
};