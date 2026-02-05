class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        vector<long long> diff(n);

        for(int i=0; i<n; i++) {
            int val = shifts[i];

            diff[0] += val;
            if(i+1 < n) {
                diff[i+1] -= val;
            }
        }
        for(int i=1; i<diff.size(); i++) {
            diff[i] += diff[i-1];
        }

        string ans;

        for(int i=0; i<n; i++) {
            int val = diff[i] % 26;

            char ch = s[i];
            int v = ch - 'a';

            int newVal = (v + val) % 26;

            char newCh = newVal + 'a';

            ans += newCh;
        }
        return ans;
    }
};