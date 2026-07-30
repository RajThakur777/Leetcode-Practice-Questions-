class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if(n <= 8) {
            return n;
        }

        int rem = (n % 8);
        int r = (n / 8);

        int sum = (r * (r + 1)) / 2;

        int next = (r + 1);

        int total = (8 * sum) + (rem * next);

        return total;
    }
};