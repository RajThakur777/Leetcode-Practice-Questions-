class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();

        string ans;

        for(int i=0; i<n; i++) {
            char ch = s[i];

            int num = (int)(ch);

            int val = num;

            string str;

            while(val > 0) {
                int d = (val % 2);

                str += (d + '0');
                val /= 2;
            }

            int sz = str.size();
            
            while(sz != 8) {
                str += '0';
                sz++;
            }

            reverse(str.begin() , str.end());

            ans += str;
        }

        cout<<ans<<endl;

        int i = 0;
        int j = ans.size()-1;

        while(i < j) {
            if(ans[i] != ans[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};