class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countVowels(string word) {
        int n = word.size();

        long long ans = 0;

        for(int i=0; i<n; i++) {
            char ch = word[i];

            if(isVowel(ch)) {
                ans += ((i + 1) * 1LL * (n - i));
            }
        }
        return ans;
    }
};