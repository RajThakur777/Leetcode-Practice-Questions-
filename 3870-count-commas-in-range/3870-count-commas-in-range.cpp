class Solution {
public:
    int countCommas(int n) {
        string str = to_string(n);

        if(str.size() <= 3) {
            return 0;
        }

        return n - 1000 + 1;
    }
};