class Solution {
public:

    static bool cmp(pair<int , int> &a , pair<int , int> &b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    const int MOD = 1e9 + 7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();

        string ans;

        for(int i=0; i<n; i++) {
            if(nums0[i] == 0 && nums1[i] > 0) {
                for(int j=0; j<nums1[i]; j++) {
                    ans += '1';
                }
            }
        }

        vector<pair<int , int>> vec;
        for(int i=0; i<n; i++) {
            if(nums0[i] > 0) {
                vec.push_back({nums1[i] , nums0[i]});
            }
        }

        if(vec.size() == 0) {
            int res = 0;

            for(char c : ans){
                res = (res * 2) % MOD;
                if(c == '1'){
                   res = (res + 1) % MOD;
                }
            }
            return res;
        }

        sort(vec.begin() , vec.end() , cmp);

        for(int i=0; i<vec.size(); i++) {
            int ones = vec[i].first;
            int zeroes = vec[i].second;

            for(int j=0; j<ones; j++) {
                ans += '1';
            }

            for(int j=0; j<zeroes; j++) {
                ans += '0';
            }
        }

        int res = 0;

        for(char c : ans){
            res = (res * 2) % MOD;
            if(c == '1'){
              res = (res + 1) % MOD;
            }
        }
        return res;
    }
};