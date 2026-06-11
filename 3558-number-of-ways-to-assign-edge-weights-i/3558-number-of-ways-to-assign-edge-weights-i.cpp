class Solution {
public:

    int ans = 0;

    const int mod = 1e9 + 7;

    long long binPow(long long a, long long b) {
        if (b == 0) return 1;

        long long half = binPow(a, b / 2);
        long long ans = (half * half) % mod;

        if (b & 1) {
            ans = (ans * a) % mod;
        }

        return ans;
    }

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<bool> &visited , int cnt) {
        visited[node] = true;

        for(auto it : mpp[node]) {
            if(!visited[it]) {
                dfs(it , mpp , visited , cnt + 1);
            }
        }

        ans = max(ans , cnt);
    } 

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        int sz = n + 1;

        vector<bool> vis(sz+1 , false);

        dfs(1 , mpp , vis , 0);

        int val = binPow(2 , ans - 1) % mod;

        return val;
    }
};