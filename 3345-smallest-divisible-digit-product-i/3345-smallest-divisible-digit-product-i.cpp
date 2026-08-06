class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i=n; i<=1000; i++) {
            int num = i;

            int prod = 1;

            while(num > 0) {
                prod = (prod * (num % 10));
                num /= 10;
            }

            if(prod % t == 0) {
                return i;
            }
        }
        return -1;
    }
};