class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = 1e9;

        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if((mid * 1LL * mid) <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};