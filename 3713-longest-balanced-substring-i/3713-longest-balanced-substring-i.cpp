class Solution {
public:

    bool isValid(vector<int> &freq) {
        int f = 0;
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                f = freq[i];
                break;
            }
        }

        for(int i=0; i<26; i++) {
            if(freq[i] > 0 && freq[i] != f) {
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {   
        int n = s.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            vector<int> freq(26 , 0);
            for(int j=i; j<n; j++) {
                freq[s[j] - 'a']++;

                if(isValid(freq)) {
                    ans = max(ans , (j - i + 1));
                }
            }
        }
        return ans;
    }
};