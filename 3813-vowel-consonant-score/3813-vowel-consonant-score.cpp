class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    bool isConsonenet(char ch) {
        return isalpha(ch) && !(ch == 'a' && ch == 'e' && ch == 'i' && ch == 'o' && ch == 'u');
    }
    
    int vowelConsonantScore(string s) {
        int n = s.size();

        int v = 0;
        int c = 0;

        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                v++;
            }
            else if(isConsonenet(s[i])){
                c++;
            }
        }
        if(c == 0) return 0;

        return (v / c);
    }
};