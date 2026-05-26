class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        string ans;
        for(char ch='A'; ch<='Z'; ch++) {
            char c = tolower(ch);
            if(mpp.find(ch) != mpp.end() && mpp.find(c) != mpp.end()) {
                string res = "";
                res += ch;

                if(res > ans) {
                    ans = res;
                }
            }
        }
        return ans;
    }
};