class Solution {
public:

    void solve(string str , int n , vector<string> &vec) {
        if(str.size() == n) {
            vec.push_back(str);
            return;
        }

        str.push_back('0');
        solve(str , n , vec);
        str.pop_back();

        str.push_back('1');
        solve(str , n , vec);
        str.pop_back();
    }

    bool isValid(string str , int k) {
        int cost = 0;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '1') {
                cost += i;
            }
        }

        if(cost > k) {
            return false;
        }

        for(int i=1; i<str.size(); i++) {
            if(str[i] == str[i-1] && str[i] == '1') {
                return false;
            }
        }
        return true;
    }
    
    vector<string> generateValidStrings(int n, int k) {
        vector<string> vec;

        string str;

        solve(str , n , vec);

        vector<string> ans;

        for(int i=0; i<vec.size(); i++) {
            if(isValid(vec[i] , k)) {
                ans.push_back(vec[i]);
            }
        }

        return ans;
    }
};