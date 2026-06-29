class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        map<char , int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int num = 0;

        for(int i=0; i<n; i++) {
            if(i + 1 < n) {
                if(mpp[s[i]] < mpp[s[i + 1]]) {
                    int v1 = mpp[s[i]];
                    int v2 = mpp[s[i + 1]];

                    num += (v2 - v1);
                    i++;
                }
                else {
                    num += mpp[s[i]];
                }
            }
            else {
                num += mpp[s[i]];
            }
        }
        return num;
    }
};