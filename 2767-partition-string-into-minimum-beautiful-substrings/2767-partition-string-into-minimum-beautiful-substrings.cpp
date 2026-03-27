class Solution {
public:
    bool isPower(int x) {
        while(x % 5 == 0 && x > 1) {
            x /= 5;
        }
        return (x == 1);
    }

    bool isValid(string str) {
        int num = 0;
        int idx = 0;

        if(str[0] == '0') {
            return false;
        }

        for(int i=str.size()-1; i>=0; i--) {
            if(str[i] == '1') {
                num += pow(2 , idx);
            }
            idx++;
        }
        return isPower(num);
    }

    int solve(int i , string &s) {
        if(i >= s.size()) {
            return 0;
        }

        int ans = INT_MAX;

        for(int j=i; j<s.size(); j++) {
            string str = s.substr(i , (j - i + 1));

            if(isValid(str)) {
                int v = solve(j+1 , s);
                if(v != INT_MAX) {
                    ans = min(ans , 1 + solve(j+1 , s));
                }
            }
        }
        return ans;
    }

    int minimumBeautifulSubstrings(string s) {
        int ans = solve(0 , s);

        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};