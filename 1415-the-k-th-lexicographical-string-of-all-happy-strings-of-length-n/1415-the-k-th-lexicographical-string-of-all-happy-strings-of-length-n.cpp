class Solution {
public:

    void solve(int idx , int n , int k , vector<string> &res , string &s) {
        if(idx == n) {
            res.push_back(s);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            if(!s.empty() && s.back() == ch) {
                continue;
            }

            s.push_back(ch);
            solve(idx+1 , n , k , res , s);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;

        string str;

        solve(0 , n , k , res , str);

        if(k > res.size()) {
            return "";
        }
        return res[k-1];
    }
};