class Solution {
public:
    int ans = 1;

    bool isPalindrome(string str) {
        int n = str.size();
        for(int i=0; i<(str.size() / 2); i++) {
            if(str[i] != str[n-i-1]) {
                return false;
            }
        }
        return true;
    }

    void solve(int idx , string s , string s1 , string s2) {
        if(idx == s.size()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                ans = max(ans , (int)((s1.size() * s2.size())));
            }
            return;
        }

        s1.push_back(s[idx]);
        solve(idx+1 , s , s1 , s2);
        s1.pop_back();

        s2.push_back(s[idx]);
        solve(idx+1 , s , s1 , s2);
        s2.pop_back();

        solve(idx+1 , s , s1 , s2);
    }

    int maxProduct(string s) {
        string s1,s2;

        solve(0 , s , s1 , s2);

        return ans;
    }
};