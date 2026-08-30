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

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();

        int m = s.size();

        parent.resize(m);
        rk.resize(m);

        for(int i=0; i<m; i++) {
            parent[i] = i;
            rk[i] = 1;
        }

        for(int i=0; i<n; i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];

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

        cout<<mpp.size()<<endl;

        string ans = s;

        for(auto it : mpp) {
           set<int> st = it.second;
           
           vector<char> vec;
           vector<int> arr;

            for(auto t : st) {
              vec.push_back(s[t]);
              arr.push_back(t);
            }

            sort(vec.begin() , vec.end());

            for(int j=0; j<vec.size(); j++) {
                ans[arr[j]] = vec[j];
            }
        }

        return ans;
    }
};