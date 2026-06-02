class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec(numRows);

        if(numRows == 1) return s;

        int curr = 0;

        int j = 0;
        char ch = 'U';

        while(j < s.size()) {
            if(ch == 'U') {
                if(curr == numRows-1) {
                    vec[curr] += s[j];
                    j++;
                    curr--;
                    ch = 'D';
                }
                else {
                    vec[curr] += s[j];
                    j++;
                    curr++;
                }
            }
            else if(ch == 'D'){
                if(curr == 0) {
                    vec[curr] += s[j];
                    j++;
                    curr++;
                    ch = 'U';
                }
                else {
                    vec[curr] += s[j];
                    j++;
                    curr--;
                }
            }
        }

        string ans;

        for(int i=0; i<vec.size(); i++) {
            ans += vec[i];
        }

        while (!ans.empty() && ans.back() == '\0') {
            ans.pop_back();
        }

        return ans;
    }
};