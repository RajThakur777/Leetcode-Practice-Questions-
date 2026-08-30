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

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {   
        int m = source.size();

        parent.resize(m);
        rk.resize(m);

        for(int i=0; i<m; i++) {
            parent[i] = i;
            rk[i] = 1;
        }

        for(int i=0; i<allowedSwaps.size(); i++) {
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];

            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) {
                continue;
            }
            else {
                Union(pu , pv);
            }
        }

        // for(int i=0; i<m; i++) {
        //     cout<<parent[i]<<" ";
        // }

        map<int , set<int>> mpp;

        for(int i=0; i<m; i++) {
            int pu = findParent(i);

            mpp[pu].insert(i);
        }

        int ans = 0;

        for(auto it : mpp) {
            set<int> st = it.second;

            int sz = st.size();

            map<int , int> mpp1;
            for(auto t : st) {
                mpp1[source[t]]++;
            }

            int c = 0;

            for(auto t : st) {
                if(mpp1.find(target[t]) != mpp1.end()) {
                    c++;
                    mpp1[target[t]]--;
                    if(mpp1[target[t]] == 0) {
                       mpp1.erase(target[t]);
                    }
                }
            }

            ans += (sz - c);
        }
        return ans;
    }
};