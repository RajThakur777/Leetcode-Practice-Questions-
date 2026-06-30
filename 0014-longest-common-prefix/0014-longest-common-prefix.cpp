class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        map<string , int> mpp;

        for(int i=0; i<n; i++) {
            string str = strs[i];

            string s;
            for(int j=0; j<str.size(); j++) {
                s += str[j];

                mpp[s]++;
            }
        }

        string ans;

        for(auto r : mpp) {
            if(r.second >= n) {
                if(r.first.size() > ans.size()) {
                    ans = r.first;
                }
            }
        }
        return ans;
    }
};