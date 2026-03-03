class Solution {
public:

    string inv(string str) {
        string res;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '1') {
                res += '0';
            }
            else {
                res += '1';
            }
        }

        reverse(res.begin() , res.end());

        return res;
    }

    string final;

    void rec(string &str , int n , int k) {
        if(n == 0) {
            final = str;
            return;
        }

        string res;
        for(int i=0; i<str.size(); i++) {
            res += str[i];
        }

        string newStr = res;

        string val = inv(res);

        newStr += '1';
        newStr += val;

        rec(newStr , n-1 , k); 
    }

    char findKthBit(int n, int k) { 
        string res;

        res += '0';

        rec(res , n , k); 

        return final[k - 1];
    }
};