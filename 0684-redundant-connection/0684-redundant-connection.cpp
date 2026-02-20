class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int findParent(int x) {
        if(x == parent[x]) return x;

        return parent[x] = findParent(parent[x]);
    }

    void Union(int u , int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) {
            return;
        }

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        rank.resize(n+1);
        parent.resize(n+1);

        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) {
                ans.push_back({u , v});
            }
            else {
                Union(u , v);
            }
        }
        return ans[ans.size() - 1];
    }
};