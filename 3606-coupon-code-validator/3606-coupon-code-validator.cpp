class Solution {
public:

    bool isValid(string s) {
        for(int i=0; i<s.size(); i++) {
            if(!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9') && !(s[i] == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<pair<string , string>> p;

        for(int i=0; i<n; i++) {
            string s1 = code[i];
            string s2 = businessLine[i];

            if(isActive[i] == true && !s1.empty() && isValid(s1) && (s2 != "invalid")) {
                p.push_back({s1 , s2});
            }
        }

        sort(p.begin() , p.end() , [](const pair<string , string>& a , const pair<string , string>& b) {
            if(a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        vector<string> ans;

        for(int i=0; i<p.size(); i++) {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};