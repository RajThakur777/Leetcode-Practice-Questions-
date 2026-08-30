class Solution {
public:
    const int mod = 1e9 + 7;

    long long binpow(long long a , long long b) {
        long long ans = 1;

        while(b > 0) {
            if(b & 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }
    
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();

        long long sum = 0;

        for(int i=0; i<n; i++) {
            long long x = nums[i];

            int w = (x % 10);
            long long d1 = (x / 10);

            string str = to_string(d1);

            string r1;
            for(int j=0; j<w; j++) {
                r1 += str[j];
            }

            string r2;
            for(int j=w; j<str.size(); j++) {
                r2 += str[j];
            }

            long long x1 = stol(r1);
            long long y1 = stol(r2);

            sum = (sum + binpow(x1 , y1)) % mod;
        }

        return (int)(sum);
    }
};