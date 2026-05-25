class Solution {
public:

    long long solve(long long n) {
        if(n == 1) {
            return 0;
        }

        long long even = LLONG_MAX;
        long long odd = LLONG_MAX;

        if(n % 2 == 0) {
            even = 1 + solve(n / 2);
        }
        else {
            odd = 1 + min(solve(n-1) , solve(n+1));
        }
        return min(even , odd);
    }

    int integerReplacement(int n) {
       return solve(n);
    }
};