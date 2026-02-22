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

        if(pu == pv) return;

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n);
        parent.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            if(findParent(u) == findParent(v)) {
                extra++;
            }
            else {
                Union(u , v);
            }
        }

        int components = 0;
        for(int i=0; i<n; i++) {
            if(parent[i] == i) {
                components++;
            }
        }
        return (extra >= components - 1 ? components - 1 : -1);
    }
};