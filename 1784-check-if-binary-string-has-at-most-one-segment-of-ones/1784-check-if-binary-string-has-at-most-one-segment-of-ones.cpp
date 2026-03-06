class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        int cnt = 0;
        int ones = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    ones++;
                    cnt = 0;
                }
            } 
        }
        if(cnt > 0) {
            ones++;
        }
        return (ones <= 1);
    }
};