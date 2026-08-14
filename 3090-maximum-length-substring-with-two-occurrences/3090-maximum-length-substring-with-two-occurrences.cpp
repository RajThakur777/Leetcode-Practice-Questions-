class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            vector<int> freq(26 , 0);
            for(int j=i; j<n; j++) {
                freq[s[j] - 'a']++;

                bool f = true;

                for(int k=0; k<26; k++) {
                    if(freq[k] != 0 && freq[k] > 2) {
                        f = false;
                        break;
                    }
                }

                if(f) {
                    ans = max(ans , (j - i + 1));
                }
            }
        }
        return ans;
    }
};