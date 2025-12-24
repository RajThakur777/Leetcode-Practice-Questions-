class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        unordered_map<char , int> mpp;

        int ans = 0;

        int i = 0;
        int maxi = 0;

        for(int j=0; j<n; j++) {
            mpp[s[j]]++;
            maxi = max(maxi , mpp[s[j]]);

            while(((j - i + 1) - maxi) > k) {
                mpp[s[i]]--;
                maxi = 0;
                for(auto it : mpp) {
                    maxi = max(maxi , it.second);
                }
                i++;
            }
            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};