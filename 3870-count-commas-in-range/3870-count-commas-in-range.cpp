class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        if(n <= 999) {
            return 0;
        }

        return n - 1000 + 1;
    }
};