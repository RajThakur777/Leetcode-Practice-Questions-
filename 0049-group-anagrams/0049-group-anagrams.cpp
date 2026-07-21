class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        map<string , vector<string>> mpp;

        for(int i=0; i<n; i++) {
            string s = strs[i];

            string copy = s;
            sort(copy.begin() , copy.end());

            mpp[copy].push_back(s);
        }

        vector<vector<string>> res;

        for(auto it : mpp) {
            vector<string> vec = it.second;

            vector<string> ans;

            for(auto s : vec) {
                ans.push_back(s);
            }

            res.push_back(ans);
        }

        return res;
    }
};