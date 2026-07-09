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
            parent[pu] = pv;
            rk[pv]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rk.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<n; i++) {
            rk[i] = 1;
        }

        for(int i=0; i<n-1; i++) {
            int u = nums[i];
            int v = nums[i+1];

            if(v - u <= maxDiff) {
                int pu = findParent(i);
                int pv = findParent(i+1);

                if(pu != pv) {
                    Union(pu , pv);
                }
            }
        }

        int q = queries.size();

        vector<bool> ans(q);

        for(int i=0; i<q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if(parent[u] == parent[v]) {
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }

        return ans;
    }
};