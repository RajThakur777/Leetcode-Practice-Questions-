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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int sz = edges.size();

        set<pair<int , int>> st;

        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            st.insert({u , v});
            st.insert({v , u});
        }  

        parent.resize(n);
        rk.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rk[i] = 1;
        }

        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) {
                continue;
            }
            else {
                Union(pu , pv);
            }
        }

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            cout<<parent[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++) {
            int node = i;
            int x = findParent(node);

            mpp[x].push_back(node);
        }

        for(auto it : mpp) {
            cout<<it.first<<" ";
            for(auto x : it.second) {
                cout<<x<<" ";
            }
            cout<<endl;
        }

        int cnt = 0;

        for(auto it : mpp) {
            vector<int> v1 = it.second;

            sort(v1.begin() , v1.end());

            if(v1.size() == 1) {
                cnt++;
            }
            else {
                bool f = true;
                for(int i=0; i<v1.size(); i++) {
                    for(int j=i+1; j<v1.size(); j++) {
                        int u = v1[i];
                        int v = v1[j];

                        if(st.find({u , v}) == st.end()) {
                            f = false;
                            break;
                        }
                    }
                    if(!f) {
                        break;
                    }
                }

                if(f) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};