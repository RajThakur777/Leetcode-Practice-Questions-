class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();

        string ans;

        int value = k;

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                ans += s[i];
            }
            else {
                if(value == 0) {
                    ans += s[i];
                }
                else {
                    int d1 = (s[i] - 'a');
                    int dist = min(26 - d1 , (s[i] - 'a'));

                    if(dist <= value) {
                        ans += 'a';
                        value -= dist;
                    }
                    else {
                        int val = value;
                        int d = (s[i] - 'a') - val;
                        char ch = (d + 'a');

                        ans += ch;
                        int rem = val;
                        value -= rem;
                    }
                }
            }
        }
        return ans;
    }
};