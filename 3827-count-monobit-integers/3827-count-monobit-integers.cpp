class Solution {
public:
    bool isValid(int x) {
        if (x == 0) return true;

        int val = __builtin_popcount(x);
        int bits = 32 - __builtin_clz(x);

        return val == bits;
    }
    
    int countMonobit(int n) {
        int ans = 0;

        for(int i=0; i<=n; i++) {
            if(isValid(i)) {
                ans++;
            }
        }
        return ans;
    }
};