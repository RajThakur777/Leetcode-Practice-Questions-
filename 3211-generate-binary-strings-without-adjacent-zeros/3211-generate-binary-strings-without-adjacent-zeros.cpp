class Solution {
public:
    void solve(int n , string res , vector<string> &ans) {
        if(res.size() == n) {
            ans.push_back(res);
            return;
        }

        if(res.empty()) {
            solve(n , res + "0" , ans);
            solve(n , res + "1" , ans);
        }
        else if(res.back() == '0') {
            solve(n , res + "1" , ans);
        }
        else if(res.back() == '1'){     
            solve(n , res + "0" , ans);
            solve(n , res + "1" , ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;

        string res;

        solve(n , res , ans);

        return ans;
    }
};