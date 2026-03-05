class Solution {
public:
    int minOperations(string s) {   
        int n = s.size();

        string res1 = s;

        if(s[0] == '0') {
            char ch = res1[0];
            int o1 = 0;

            for(int i=1; i<n; i++) {
                if(res1[i] == ch) {
                    o1++;
                }
                ch = (ch == '0' ? '1' : '0');
            }

            char ch2 = '1';
            int o2 = 1;

            for(int i=1; i<n; i++) {
                if(res1[i] == ch2) {
                    o2++;
                }
                ch2 = (ch2 == '1' ? '0' : '1');
            }            

            return min(o1 , o2);
        }
        else {
            char ch = res1[0];
            int o1 = 0;

            for(int i=1; i<n; i++) {
                if(res1[i] == ch) {
                    o1++;
                }
                ch = (ch == '0' ? '1' : '0');
            }

            char ch2 = '0';
            int o2 = 1;

            for(int i=1; i<n; i++) {
                if(res1[i] == ch2) {
                    o2++;
                }
                ch2 = (ch2 == '1' ? '0' : '1');
            }            

            return min(o1 , o2);
        }
    }
};