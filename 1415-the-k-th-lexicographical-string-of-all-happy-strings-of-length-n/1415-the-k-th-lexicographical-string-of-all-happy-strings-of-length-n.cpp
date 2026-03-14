class Solution {
public:

    void solve(int idx , int n , int k , string res , vector<string> &vec) {
        if(idx == n) {
            vec.push_back(res);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            if(!res.empty() && res.back() == ch) {
                continue;
            }

            res.push_back(ch);
            solve(idx+1 , n , k , res , vec);
            res.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> vec;

        string res;

        solve(0 , n , k , res , vec);

        if(vec.size() < k) {
            return "";
        }      

        return vec[k-1];
    }
};