class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int ans = 0;

        if(k == 1) {
            return (r - l + 1);
        }

        long long num = 0;

        while(pow(num , k) <= r) {
            if(pow(num , k) >= l && pow(num , k) <= r) {
                ans++;
            }
            num++;
        }
        return ans;
    }
};