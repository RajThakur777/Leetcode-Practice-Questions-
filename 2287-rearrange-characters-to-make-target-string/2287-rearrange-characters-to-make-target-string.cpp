class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.size();

        map<char , int> mpp1;

        for(int i=0; i<n; i++) {
            mpp1[s[i]]++;
        }

        map<char , int> mpp2;
        for(int i=0; i<target.size(); i++) {
            mpp2[target[i]]++;
        }

        int ans = INT_MAX;

        for(int i=0; i<target.size(); i++) {
            if(mpp1.find(target[i]) == mpp1.end()) {
                return 0;
            }
            else {
                ans = min(ans , (mpp1[target[i]] / mpp2[target[i]]));
            }
        }

        return ans;
    }
};