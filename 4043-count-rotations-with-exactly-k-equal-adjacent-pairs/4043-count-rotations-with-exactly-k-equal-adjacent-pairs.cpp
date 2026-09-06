class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        int r = 0;

        int v = 0;

        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                r++;
            }
        }

        if(r == k) {
            v++;
        }

        int ans = 1;

        for(int len=0; len<=n-2; len++) {
            ans++;

            string r1;
            for(int j=0; j<=len; j++) {
                r1 += s[j];
            }

            string r2;
            for(int j=len+1; j<n; j++) {
                r2 += s[j];
            }

            string res;

            res += r2;
            res += r1;

            int val = 0;

            for(int k=0; k<n-1; k++) {
                if(res[k] == res[k+1]) {
                    val++;
                }
            }

            if(val == k) {
                v++;
            }
        }

        return v;
    }
};