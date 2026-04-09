class Solution {
public:
    int minOperations(int k) { 
        long long ans = LLONG_MAX;

        if(k == 1) return 0;

        long long num = 1;
        for(int i=0; i<=1e5; i++) {
            num = (1 + i);
            long long inc = i;
            long long dup = ((k + num - 1) / num) - 1;

            ans = min(ans , (long long)inc + dup);
        }
        return (int)ans;
    }
};