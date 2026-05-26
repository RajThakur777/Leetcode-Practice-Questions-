class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {
                mpp[ch] = i;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                if(mpp.find(ch) == mpp.end()) {
                    mpp[ch] = i;
                }
            }
        }

        int ans = 0;

        for(char ch='A'; ch<='Z'; ch++) {
            char c = tolower(ch);
            if(mpp.find(ch) != mpp.end() && mpp.find(c) != mpp.end()) {
                int i1 = mpp[ch];
                int i2 = mpp[c];

                if(i1 > i2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};