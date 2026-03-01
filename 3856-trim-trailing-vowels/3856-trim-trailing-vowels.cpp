class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string trimTrailingVowels(string s) {
        int n = s.size();

        int idx = -1;

        for(int i=n-1; i>=0; i--) {
            if(!isVowel(s[i])) {
                idx = i;
                break;
            }
        }

        if(idx == -1) return "";

        string res;
        for(int i=0; i<=idx; i++) {
            res += s[i];
        }
        return res;
    }
};