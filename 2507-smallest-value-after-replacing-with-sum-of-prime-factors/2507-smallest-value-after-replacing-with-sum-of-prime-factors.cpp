class Solution {
public:
    int N = 1e5 + 1;
    vector<int> spf;

    Solution() {
        spf.resize(N);
        sieve();
    }

    void sieve() {
        for(int i = 0; i < N; i++) {
            spf[i] = i;
        }

        for(int i = 2; i * i < N; i++) {
            if(spf[i] == i) { // prime
                for(int j = i * i; j < N; j += i) {
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    int solve(int x) {
        int sum = 0;

        while(x > 1) {
            sum += spf[x];
            x /= spf[x];
        }

        return sum;
    }

    int smallestValue(int n) {   
        while(true) {
            int sum = solve(n);

            if(sum == n) break;
            n = sum;
        }
        return n;
    }
};