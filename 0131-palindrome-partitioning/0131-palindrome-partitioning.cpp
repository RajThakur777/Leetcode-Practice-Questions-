class Solution {
public:
    bool isPalindrome(string str) {
        int i = 0;
        int j = str.size() - 1;

        while(i <= j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int idx , string s , vector<string> &res , vector<vector<string>> &ans) {
        if(idx >= s.size()) {
            ans.push_back(res);
            return;
        }

        for(int i=idx; i<s.size(); i++) {
            string str = s.substr(idx , (i - idx + 1));

            if(isPalindrome(str)) {
                res.push_back(str);

                solve(i+1 , s , res , ans);

                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        vector<string> res;

        solve(0 , s , res , ans);

        return ans;
    }
};