class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();

        unordered_map<long long , vector<long long>> mpp1;
        for(int i=0; i<n; i++) {
            mpp1[arr[i]].push_back(i);
        }

        unordered_map<long long , vector<long long>> mpp2;
        for(auto it : mpp1) {
            vector<long long> vec = it.second;

            vector<long long> prefix(vec.size());
            prefix[0] = vec[0];

            for(int j=1; j<vec.size(); j++) {
                prefix[j] = (prefix[j-1] + vec[j]);
            }

            mpp2[it.first] = prefix;
        }

        vector<long long> ans(n);

        for(auto it : mpp1) {
            vector<long long> prefix = mpp2[it.first];
            vector<long long> vec = it.second;

            for(int i=0; i<vec.size(); i++) {
                long long left = ((i) * (vec[i])) - (i > 0 ? prefix[i - 1] : 0);
                long long right = ((prefix[vec.size() - 1] - prefix[i])) - ((vec.size() - i - 1) * (vec[i]));

                ans[vec[i]] = left + right;
            }
        }
        return ans;
    }
};