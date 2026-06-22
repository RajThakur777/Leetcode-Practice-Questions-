class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();

        int k = maxLetters;

        map<string , int> mpp1;
        map<char , int> mpp2;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp2[s[j]]++;

            while((j - i + 1) > maxSize || mpp2.size() > k) {
                mpp2[s[i]]--;
                if(mpp2[s[i]] == 0) {
                    mpp2.erase(s[i]);
                }
                i++;
            }

            while((j - i + 1) >= minSize && mpp2.size() <= k) {
                string str = s.substr(i , (j - i + 1));

                mpp1[str]++;

                mpp2[s[i]]--;

                if(mpp2[s[i]] == 0) {
                    mpp2.erase(s[i]);
                }

                i++;
            }
        }  

        int ans = 0;

        for(auto it : mpp1) {
            ans = max(ans , it.second);
        }

        return ans;
    }
};