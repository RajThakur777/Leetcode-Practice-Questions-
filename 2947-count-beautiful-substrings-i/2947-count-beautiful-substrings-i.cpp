class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int beautifulSubstrings(string s, int k) { 
        int n = s.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            int vowel = 0;
            int consonent = 0;
            for(int j=i; j<n; j++) {
                if(isVowel(s[j])) {
                    vowel++;
                }
                else {
                    consonent++;
                }

                if((vowel == consonent) && (vowel * consonent) % k == 0) {
                    ans++;
                }
            }
        }  
        return ans;
    }
};