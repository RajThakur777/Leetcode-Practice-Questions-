class Solution {
public:
    int minSteps(string s, string t) {   
        int n = s.size();
        int m = t.size();

        vector<int> freq1(26) , freq2(26);

        for(int i=0; i<n; i++) {
            freq1[s[i] - 'a']++;
        }

        for(int i=0; i<m; i++) {
            freq2[t[i] - 'a']++;
        }

        int ans = 0;

        for(int i=0; i<26; i++) {
            ans += abs(freq1[i] - freq2[i]);
        }
        return ans;
    }
};