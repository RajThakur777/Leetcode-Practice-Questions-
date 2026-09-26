class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = knowledge.size();

        map<string , string> mpp;

        for(int i=0; i<n; i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                int j = i;

                string r;

                while(j < s.size() && s[j] != ')') {
                    r += s[j];
                    j++;
                }

                string res = r.substr(1);

                if(mpp.find(res) == mpp.end()) {
                    ans += '?';
                }
                else {
                    ans += mpp[res];
                }

                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};