class Solution {
public:
    bool checkGoodInteger(int n) {
        int s1 = 0;
        int s2 = 0;

        int num = n;

        while(num > 0) {
            int dig = (num % 10);
            s1 += dig;
            s2 += ((dig * dig));
            num /= 10;
        }

        return (s2 - s1) >= 50;
    }
};