class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);

        long long x = 0;
        long long sum = 0;

        for(int i=0; i<str.size(); i++) {
            if(str[i] != '0') {
                sum += (str[i] - '0');
                x = (x * 10 + (str[i] - '0'));
            }
        }

        return (x * 1LL * sum);
    }
};