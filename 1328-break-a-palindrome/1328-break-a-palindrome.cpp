class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

        if(n == 1) {
            return "";
        }

        string ans = palindrome;
        bool flag = false;

        for(int i=0; i<n/2; i++) {
            if(palindrome[i] != 'a') {
                ans[i] = 'a';
                flag = true;
                break;
            }
        }

        if(flag) {
            return ans;
        }
        else {
            string res = palindrome;
            res[n-1] = 'b';

            return res;
        }
    }
};