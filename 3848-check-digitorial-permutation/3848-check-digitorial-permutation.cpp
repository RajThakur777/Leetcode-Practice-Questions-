class Solution {
public:

    int rec(int x) {
        if(x == 0 || x == 1) return 1;

        return x * rec(x-1);
    }

    int solve(string str) {
        int sum = 0;

        for(int i=0; i<str.size(); i++) {
            int num = str[i] - '0';

            int fac = rec(num);

            sum += fac;
        }
        return sum;
    }
    
    bool isDigitorialPermutation(int n) {
        string str = to_string(n);

        int sum = solve(str);

        string str1 = to_string(sum);

        map<char , int> mpp;
        for(int i=0; i<str1.size(); i++) {
            mpp[str1[i]]++;
        }

        map<char , int> mpp2;
        for(int i=0; i<str.size(); i++) {
            mpp2[str[i]]++;
        }

        if(str1.size() != str.size()) return false;

        for(int i=0; i<str.size(); i++) {
            if(mpp.find(str[i]) == mpp.end()) {
                return false;
            }

            if(mpp[str[i]] != mpp2[str[i]]) {
                return false;
            }
        }
        return true;
    }
};