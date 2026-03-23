class Solution {
public:
    int numSplits(string s) {
        int n = s.size();

        vector<int> prefix(n);
        prefix[0] = 1;

        set<int> st1;
        st1.insert(s[0]);

        for(int i=1; i<n; i++) {
            if(st1.find(s[i]) == st1.end()) {
                prefix[i] = prefix[i-1] + 1;
                st1.insert(s[i]);
            }
            else {
                prefix[i] = prefix[i-1];
            }
        }

        vector<int> suffix(n);
        suffix[n-1] = 1;

        set<int> st2;
        st2.insert(s[n-1]);

        for(int i=n-2; i>=0; i--) {
            if(st2.find(s[i]) == st2.end()) {
                suffix[i] = suffix[i+1] + 1;
                st2.insert(s[i]);
            }
            else {
                suffix[i] = suffix[i+1];
            }
        }

        int ans = 0;

        for(int i=0; i<n-1; i++) {
            if(prefix[i] == suffix[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};