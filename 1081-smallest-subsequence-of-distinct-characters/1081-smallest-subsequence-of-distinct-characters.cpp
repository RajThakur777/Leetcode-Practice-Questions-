class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<bool> vis(26 , false);

        vector<int> last_occ(26);

        for(int i=0; i<n; i++) {
            char ch = s[i];

            last_occ[ch - 'a'] = i;
        }

        string ans;

        for(int i=0; i<n; i++) {
            if(vis[s[i] - 'a']) {
                continue;
            }

            while(ans.size() > 0 && ans.back() > s[i] && last_occ[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += s[i];
            vis[s[i] - 'a'] = true;
        }

        return ans;
    }
};