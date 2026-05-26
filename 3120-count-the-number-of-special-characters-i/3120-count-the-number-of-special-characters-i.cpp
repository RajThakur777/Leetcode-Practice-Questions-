class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        map<char , int> mpp;
        for(int i=0; i<word.size(); i++) {
            char ch = word[i];

            mpp[ch]++;
        }

        int ans = 0;
        for(char ch='A'; ch<='Z'; ch++) {
            char c = tolower(ch);

            if(mpp.find(c) != mpp.end() && mpp.find(ch) != mpp.end()) {
                ans++;
            }
        }
        return ans;
    }
};