class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        vector<int> ans;

        char ch = s[0];
        int cnt = 1;

        for(int i=1; i<n; i++) {
            if(s[i] == ch) {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    ans.push_back(cnt);
                }
                cnt = 1;
                ch = s[i];
            }
        }
        if(cnt > 0) {
            ans.push_back(cnt);
        }

        int res = 0;
        for(int i=1; i<ans.size(); i++) {
            if(ans[i] == ans[i-1]) {
                res += ans[i];
            }
            else {
                res += min(ans[i] , ans[i-1]);
            }
        }
        return res;
    }
};