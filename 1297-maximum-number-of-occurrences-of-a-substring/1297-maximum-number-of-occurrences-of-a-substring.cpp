class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();

        map<string , int> mpp1;

        for(int k=minSize; k<=maxSize; k++) {
            int len = k;

            map<char , int> mpp2;

            int i = 0;
            for(int j=0; j<n; j++) {
                mpp2[s[j]]++;

                while((j - i + 1) > len) {
                    mpp2[s[i]]--;
                    if(mpp2[s[i]] == 0) {
                        mpp2.erase(s[i]);
                    }
                    i++;
                }

                if((j - i + 1) == len && mpp2.size() <= maxLetters) {
                    string str = s.substr(i , (j - i + 1));

                    mpp1[str]++;
                }
            }
        }

        int ans = 0;

        for(auto it : mpp1) {
            ans = max(ans , it.second);
        }

        return ans;
    }
};