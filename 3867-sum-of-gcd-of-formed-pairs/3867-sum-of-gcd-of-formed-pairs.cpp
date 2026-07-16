class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> m(n);
        vector<long long> prefix(n);

        m[0] = nums[0];
        for(int i=1; i<n; i++) {
            m[i] = max(m[i-1] , (long long)nums[i]);
        }

        for(int i=0; i<n; i++) {
            prefix[i] = __gcd((long long)nums[i] , m[i]);
        }

        sort(prefix.begin() , prefix.end());

        int i = 0;
        int j = n-1;

        long long sum = 0;

        while(i < j) {
            sum += __gcd(prefix[i] , prefix[j]);
            i++;
            j--;
        }

        return sum;
    }
};