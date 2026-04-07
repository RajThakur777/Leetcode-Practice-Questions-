class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long  , vector<long long>> mpp1;
        for(int i=0; i<n; i++) {
            mpp1[nums[i]].push_back(i);
        }

        unordered_map<long long , vector<long long>> mpp2;
        for(auto it : mpp1) {
            vector<long long> v = it.second;
            vector<long long> prefix(it.second.size());

            prefix[0] = v[0];
            for(int j=1; j<v.size(); j++) {
                prefix[j] = prefix[j-1] + v[j];
            }

            mpp2[it.first] = prefix;
        }

        vector<long long> ans(n);

        for(auto it : mpp1) {
            vector<long long> v = it.second;
            vector<long long> prefix = mpp2[it.first];

            for(int j=0; j<v.size(); j++) {

                long long left = ((v[j] * j)) - ((j > 0 ? (prefix[j-1]) : 0));
                long long right = ((prefix[v.size()-1] - prefix[j])) - ((v.size() - j - 1) * v[j]);

                ans[v[j]] = (left + right);
            }
        }
        return ans;
    }
};