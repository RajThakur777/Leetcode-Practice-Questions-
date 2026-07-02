class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m != n) {
            return false;
        }

        vector<int> freq1(26 , 0);
        vector<int> freq2(26 , 0);

        for(int i=0; i<s.size(); i++) {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }

        for(int i=0; i<26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};