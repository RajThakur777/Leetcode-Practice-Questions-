class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();

        unordered_map<char , int> mpp;

        string res;

        for(int i=0; i<n; i++) {
            if(mpp.find(s[i]) != mpp.end() && (res.size() - mpp[s[i]]) <= k) {
                continue;
            }

            res += s[i];
            mpp[s[i]] = res.size() - 1;
        }
        return res;
    }
};