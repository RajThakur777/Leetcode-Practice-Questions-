class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1;

        if(n == 1) {
            return "1";
        }

        string res;
        res += '1';

        while(cnt != n) {
            string v = res;
            char ch = v[0];
            int count = 1;

            string ans;

            for(int j=1; j<v.size(); j++) {
                if(v[j] == ch) {
                    count++;
                }
                else {
                    ans += (count + '0');
                    ans += ch;
                    count = 1;
                    ch = v[j];
                }
            }

            ans += (count + '0');
            ans += ch;

            cout<<ans<<endl;

            res = ans;
            cnt++;
        }

        return res;
    }
};