class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        vector<int> freq(26);
        for(int i=0; i<n; i++) {
            freq[s[i] - 'a']++;
        }

        string left;
        char ch;
        int odd = 0;

        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                if(freq[i] % 2 != 0) {
                    ch = (i + 'a');
                    odd++;
                }

                int half = (freq[i] / 2);

                while(half--) {
                    left += (i + 'a');
                }
            }
        }

        string right;

        right = left;

        reverse(right.begin() , right.end());

        if(odd > 0) {
            left += ch; 
        }

        string ans;
        ans += left;
        ans += right;

        return ans;
    }
};