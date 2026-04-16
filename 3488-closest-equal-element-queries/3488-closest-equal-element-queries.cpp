class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int sz = queries.size();

        vector<int> ans(sz);

        for(int i=0; i<sz; i++) {
            int idx = queries[i];

            const vector<int>& vec = mpp[nums[idx]];

            int SZ = vec.size();

            if(vec.size() == 1) {
                ans[i] = -1;
            }
            else {
                int it = lower_bound(vec.begin() , vec.end() , idx) - vec.begin();

                int p1 = (it + 1) % SZ;
                int p2 = (it - 1 + SZ) % SZ;

                int d1 = abs(vec[p1] - idx);
                int d2 = abs(idx - vec[p2]);

                int a1 = min(d1 , n - d1);
                int a2 = min(d2 , n - d2);

                ans[i] = min(a1 , a2);
            }
        }
        return ans;
    }
};