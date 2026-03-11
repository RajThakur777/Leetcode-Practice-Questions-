class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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
        else {
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if(rank[pv] < rank[pu]) {
                parent[pv] = pu;
            }
            else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }

    static bool cmp(vector<int> &a , vector<int> &b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> arr = queries;

        int m1 = edgeList.size();
        int m2 = queries.size();

        sort(queries.begin() , queries.end() , cmp);
        sort(edgeList.begin() , edgeList.end() , cmp);

        vector<bool> ans(m2);

        map<pair<pair<int , int> , int> , bool> mpp;

        int j = 0;
        for(int i=0; i<m2; i++) {
            while(j < m1 && edgeList[j][2] < queries[i][2]) {
                Union(edgeList[j][0] , edgeList[j][1]);
                j++;
            }

            if(findParent(queries[i][0]) == findParent(queries[i][1])) {
                mpp[{{queries[i][0] , queries[i][1]} , queries[i][2]}] = true;
            }
            else {
                mpp[{{queries[i][0] , queries[i][1]} , queries[i][2]}] = false;
            }
        }

        for(int i=0; i<m2; i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            int l = arr[i][2];

            ans[i] = mpp[{{u , v} , l}];
        }
        return ans;
    }
};