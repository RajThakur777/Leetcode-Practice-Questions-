class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum_odd = 0;
        int sum_even = 0;

        int cnt1 = n;
        int cnt2 = n;

        int num1 = 1;
        int num2 = 2;

        while(cnt1--) {
            sum_odd += num1;
            num1 += 2;
        }

        while(cnt2--) {
            sum_even += num2;
            num2 += 2;
        }

        return __gcd(sum_odd , sum_even);
    }
};