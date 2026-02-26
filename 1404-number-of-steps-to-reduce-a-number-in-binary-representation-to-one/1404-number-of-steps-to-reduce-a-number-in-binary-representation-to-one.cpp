class Solution {
public:

    string addition(string str) {
        reverse(str.begin() , str.end());

        int carry = 0;

        string ans;
        int idx = 0;

        ans += '0';
        carry = 1;

        for(int i=str.size()-2; i>=0; i--) {
            if(str[i] == '1') {
                ans += '0';
            }
            else {
                ans += '1';
                idx = i;
                break;
            }
        }

        if(idx > 0) {
            for(int i=idx-1; i>=0; i--) {
                ans += str[i];
            }
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }

    int numSteps(string s) {
        int n = s.size();

        int cnt = 0;

        for(int i=n-1; i>0; i--) {
            if(s[i] == '0') {
                int j = i;
                while(j >= 0 && s[j] == '0') {
                    cnt++;
                    j--;
                }
                i = (j + 1);
            }
            else {
                string res;
                for(int j=i; j>=0; j--) {
                    res += s[j];
                }

                string ans = addition(res);

                cnt++;
                i++;

                s = ans;
            }
        }
        return cnt;
    }
};