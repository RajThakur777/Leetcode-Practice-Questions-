class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int mini1 = min(numOnes , k);

        int ans = mini1;

        k -= mini1;

        if(k != 0) {
            int mini2 = min(numZeros , k);

            k -= mini2;
        }

        if(k != 0) {
            int mini3 = min(numNegOnes , k);

            ans += (mini3 * (-1));
        }
        return ans;
    }
};