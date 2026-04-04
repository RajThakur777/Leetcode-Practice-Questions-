class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();

        vector<int> arr(n);

        for(int i=0; i<n; i++) {
            int val = ((word[i] - '0')) % m;
            arr[i] = val;
        }

        vector<int> ans(n);

        long long prev = 0;
        for(int i=0; i<n; i++) {
            prev = ((prev * 10) + arr[i]) % m;

            if(prev == 0) {
                ans[i] = 1;
            }
            else {
                ans[i] = 0;
            }
        }
        return ans;
    }
};