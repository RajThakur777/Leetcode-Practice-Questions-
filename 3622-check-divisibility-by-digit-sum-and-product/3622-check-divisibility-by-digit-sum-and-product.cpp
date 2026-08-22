class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0;
        int p = 1;

        int v1 = n;
        int v2 = n;

        while(v1 > 0) {
            s += (v1 % 10);
            v1 /= 10;
        }

        while(v2 > 0) {
            p *= (v2 % 10);
            v2 /= 10;
        }

        return (n % (p + s) == 0);
    }
};