class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char , int> mpp;

        for(int i=0; i<chars.size(); i++) {
            mpp[chars[i]] = vals[i];
        }

        int n = s.size();

        vector<int> arr(n);

        for(int i=0; i<n; i++) {
            char ch = s[i];

            if(mpp.find(ch) == mpp.end()) {
                arr[i] = (ch - 'a') + 1;
            }
            else {
                arr[i] = mpp[ch];
            }
        }

        int ans = 0;
        int cs = 0;

        for(int i=0; i<n; i++) {
            cs += arr[i];

            ans = max(ans , cs);

            if(cs < 0) {
                cs = 0;
            }
        }

        return ans;
    }
};