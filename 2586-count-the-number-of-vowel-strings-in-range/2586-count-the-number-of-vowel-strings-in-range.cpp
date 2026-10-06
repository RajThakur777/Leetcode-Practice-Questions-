class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;

        for(int i=left; i<=right; i++) {
            string str = words[i];

            if(isVowel(str[0]) && isVowel(str[str.size() - 1])) {
                ans++;
            }
        }

        return ans;
    }
};