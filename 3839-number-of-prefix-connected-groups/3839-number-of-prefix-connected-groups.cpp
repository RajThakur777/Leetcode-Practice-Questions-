class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string , int> mpp;

        for(int i=0; i<words.size(); i++) {
            string res = words[i];

            string val = res.substr(0 , k);

            if(val.size() >= k) {
                mpp[val]++;
            }
        }

        int ans = 0;
        for(auto it : mpp) {
            if(it.second >= 2) {
                ans++;
            }
        }
        return ans;
    }
};