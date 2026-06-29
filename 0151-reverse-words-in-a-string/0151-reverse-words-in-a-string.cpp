class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;

        int idx = -1;
        for(int i=0; i<s.size(); i++) {
            if(s[i] != ' ') {
                idx = i;
                break;
            }
        }

        for(int i=idx; i<s.size(); i++) {
            int j = i;

            string str;

            while(j < s.size() && s[j] != ' ') {
                str += s[j];
                j++;
            }

            while(j < s.size() && s[j] == ' ') {
                j++;
            }

            i = j - 1;
            vec.push_back(str);
        }

        reverse(vec.begin() , vec.end());

        string ans;

        for(int i=0; i<vec.size(); i++) {
            if(i == vec.size() - 1) {
                ans += vec[i];
            }
            else {
                ans += vec[i];
                ans += ' ';
            }
        }
        return ans;
    }
};