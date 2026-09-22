class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();

        int ans = 0;

        bool f = false;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(s[i] == s[j] && i != j) {
                    f = true;
                    ans = max(ans , ((j - i + 1) - 2));
                }
            }
        }

        if(!f) return -1;

        return ans;
    }
};