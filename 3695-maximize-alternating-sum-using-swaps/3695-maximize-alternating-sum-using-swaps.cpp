class Solution {
public:
    vector<int> parent;
    vector<int> rk;

    int findParent(int x) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void Union(int u , int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) {
           return;
        }

        if(rk[pu] < rk[pv]) {
            parent[pu] = pv;
        }
        else if(rk[pv] < rk[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rk[pu]++;
        }
    }

    int n;

    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        n = nums.size();

        parent.resize(n);
        rk.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rk[i] = 1;
        }

        for(int i=0; i<swaps.size(); i++) {
            int u = swaps[i][0];
            int v = swaps[i][1];

            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) {
                continue;
            }

            Union(pu , pv);
        }

        map<int , set<int>> mpp1;
        map<int , vector<int>> mpp2;

        for(int i=0; i<n; i++) {
            int pu = findParent(i);

            mpp1[pu].insert(i);
            mpp2[pu].push_back(nums[i]);
        }

        vector<int> ans = nums;

        for(auto it : mpp1) {
            set<int> st = it.second;
            vector<int> v = mpp2[it.first];

            sort(v.rbegin() , v.rend());

            int j = 0;
            for(auto t : st) {
                if(t % 2 == 0) {
                    ans[t] = v[j];
                    j++;
                }
            }

            for(auto t : st) {
                if(t % 2 != 0) {
                    ans[t] = v[j];
                    j++;
                }
            }
        }

        long long s1 = 0;
        long long s2 = 0;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                s1 += ans[i];
            }
            else {
                s2 += ans[i];
            }
        }

        return (s1 - s2);
    }
};