class Solution {
public:

    bool isPrime(int x) {
        if(x < 2) return false;

        for(int i=2; i*i<=x; i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int sumOfPrimesInRange(int n) {
        int l = n;

        int num = 0;
        int ele = n;
        while(ele > 0) {
            int dig = ele % 10;
            num = (num * 10) + dig;
            ele /= 10;
        }

        int r = num;

        int l1 = min(l , r);
        int l2 = max(l , r);

        int cnt = 0;

        for(int i=l1; i<=l2; i++) {
            if(isPrime(i)) {
                cnt += i;
            }
        }
        return cnt;
    }
};